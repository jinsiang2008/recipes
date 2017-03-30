#include "redis_client.h"

#include "hiredis/adapters/libevent.h"

RedisClient::RedisClient(const std::string hostname, const int port)
    : hostname_(hostname), port_(port), context_(nullptr, redisAsyncFree),
      event_base_(nullptr, event_base_free) {}

RedisClient::~RedisClient() {
  if (context_) {
    context_.release();
  }
  if (thread_.joinable()) {
    thread_.join();
  }
}

void RedisClient::connect() {
  if (!event_base_) {
    event_base_.reset(event_base_new());
  }
  if (!context_) {
    context_.reset(redisAsyncConnect(hostname_.c_str(), port_));
    redisLibeventAttach(context_.get(), event_base_.get());
  }
}

bool RedisClient::connected() const { return (context_ && !context_->err); }

void RedisClient::run_loop() { event_base_dispatch(event_base_.get()); }

void RedisClient::start() {
  if (thread_.get_id() == std::thread::id()) {
    thread_ = std::thread(&RedisClient::run_loop, this);
  }
}

void redis_async_callback(redisAsyncContext *, void *reply, void *privdata);

int RedisClient::subscribe(const std::string channel, subscribe_callback cb) {
  if (!connected()) {
    return REDIS_ERR;
  }
  cb_ = cb;
  redisAsyncCommand(context_.get(), redis_async_callback, this, "SUBSCRIBE %s",
                    channel.c_str());
  return REDIS_OK;
}

void redis_async_callback(redisAsyncContext *context, void *r, void *privdata) {
  redisReply *reply = static_cast<redisReply *>(r);
  RedisClient *pthis = static_cast<RedisClient *>(privdata);
  if (reply == NULL)
    return;

  if (reply && reply->type == REDIS_REPLY_ARRAY) {
    if (reply->elements > 2 && !strcmp(reply->element[0]->str, "message")) {
      const char *message = reply->element[2]->str;
      if (pthis->cb_) {
        pthis->cb_(message);
      }
    }
  }
}

class Config {
public:
  void update(const std::string &msg) {
    std::cout << "msg:" << msg << std::endl;
  };
};

int main(int argc, char **argv) {
  std::cout << "Main" << std::endl;
  RedisClient client("127.0.0.1", 6379);
  client.connect();
  Config config;

  client.subscribe("test",
                   std::bind(&Config::update, &config, std::placeholders::_1));
  client.start();
  while (1) {
    ;
  }
  return 0;
}
