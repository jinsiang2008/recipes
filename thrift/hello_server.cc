#include "gen-cpp/HelloSvc.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace ::apache::thrift::server;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using boost::shared_ptr;
using boost::make_shared;

class HelloSvcHandler : public HelloSvcIf {
public:
    virtual void hello_func(std::string& _return) override {
 				std::cout << "Server recived request" << std::endl;
        _return = "Server response";
    }
};

int main() {
	int port = 9090;
    auto handler = make_shared<HelloSvcHandler>();
    auto proc = make_shared<HelloSvcProcessor>(handler);
    auto trans_svr = make_shared<TServerSocket>(port);
    auto trans_fac = make_shared<TBufferedTransportFactory>();
    auto proto_fac = make_shared<TBinaryProtocolFactory>();
    TSimpleServer server(proc, trans_svr, trans_fac, proto_fac);
    std::cout << "Hello server start listening on port " << port << std::endl;
    server.serve();
    return 0;
}

