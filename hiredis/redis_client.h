//
// Created by Hongyi Shen on 3/17/17.
//

#include <iostream>
#include <thread>
#include <hiredis/hiredis.h>

struct event_base;
struct redisAsyncContext;

typedef  std::unique_ptr<event_base, void (*)(event_base *)>
     event_base_unique_ptr;

typedef std::unique_ptr<redisAsyncContext, void (*)(redisAsyncContext *)>
     redisAsyncContext_unique_ptr;

typedef std::function<void(const std::string msg)> subscribe_callback;

extern "C" void redis_async_callback(redisAsyncContext *, void *reply, void *privdata);

typedef void (redisCallbackFn)(struct redisAsyncContext*, void*, void*);
class RedisClient
{
private:
    const std::string hostname_;
    const int port_;
    redisAsyncContext_unique_ptr context_;
    std::thread thread_;
    event_base_unique_ptr event_base_;
    subscribe_callback cb_;

    void run_loop();

public:
    RedisClient(const std::string hostname, const int port);
    ~RedisClient();
    void connect();
    bool connected() const;
    //static void onMessage(redisAsyncContext *context, void *reply, void *privdata);
    //int subscribe(redisCallbackFn *fn, void *privdata, std::string command);
    int subscribe(const std::string channel, subscribe_callback cb);
    friend void redis_async_callback(redisAsyncContext *, void *reply, void *privdata);
    void start();
};
