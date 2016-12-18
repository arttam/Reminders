#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>
#include <signal.h>
#include "filehandler.h"
#include "rdb.h"

#include "session.h"

using boost::asio::ip::tcp;

class Server
{
    std::string rdbPath_;
    RDB rdb_;
    boost::asio::io_service io_service_;
    tcp::acceptor acceptor_;
    tcp::socket socket_;
    boost::asio::signal_set signals_;

    void do_accept();
    void do_await_stop();

public:
    Server(short port, const char *rdbPath);

    void run();
};

#endif // SERVER_H
