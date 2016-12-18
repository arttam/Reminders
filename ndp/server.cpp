#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

#include "server.h"

using boost::asio::ip::tcp;

Server::Server(short port, const char *rdbPath)
    : rdbPath_(rdbPath)
    , io_service_()
    , acceptor_(io_service_, tcp::endpoint(tcp::v4(), port))
    , socket_(io_service_)
    , signals_(io_service_)
{
    fileHandler _fh(rdbPath);
    if (!_fh) {
        throw std::runtime_error("Failed to open db file for reading");
    }

    if (!rdb_.readDB(_fh.getContents())) {
        throw std::runtime_error("Failed to get valid data");
    }

    signals_.add(SIGTERM);
    do_await_stop();

    do_accept();
}

void Server::run()
{
    io_service_.run();
}

void Server::do_accept()
{
    acceptor_.async_accept(socket_,
        [this](boost::system::error_code ec)
        {
            // Closing connections already?
            if (!acceptor_.is_open())
                return;

            if (!ec) {
                std::make_shared<Session>(Session(std::move(socket_), rdb_, rdbPath_))->start();
            }

            do_accept();
        }
    );
}

void Server::do_await_stop()
{
    signals_.async_wait(
        [this](boost::system::error_code /*ec*/, int /*signo*/)
        {
            acceptor_.close();
        }
    );
}
