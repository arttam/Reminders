#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <memory>
#include <utility>
#include <regex>
#include <boost/asio.hpp>

#include "rdb.h"

using boost::asio::ip::tcp;

class Session: public std::enable_shared_from_this<Session>
{
    const std::regex reFwdSlash_;
    tcp::socket socket_;
    RDB& rdb_;

    char request_[8192];
    std::vector<char> response_;

    void do_read();
    void do_write(std::size_t len);
    void parseRequest(std::size_t len);

public:
    Session(tcp::socket socket, RDB& rdb);

    void start();
};

#endif // SESSION_H
