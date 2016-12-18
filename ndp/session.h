#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <memory>
#include <utility>
#include <regex>
#include <boost/asio.hpp>

#include "filehandler.h"
#include "rdb.h"

using boost::asio::ip::tcp;

class Session: public std::enable_shared_from_this<Session>
{
    const std::regex reFwdSlash_;
    tcp::socket socket_;
    std::string& rdbPath_;
    RDB& rdb_;

    char request_[8192];
    std::vector<char> response_;

    void do_read();
    void do_write();
    void parseRequest(std::size_t len);

public:
    Session(tcp::socket socket, RDB& rdb, std::string& rdbPath);

    void start();
};

#endif // SESSION_H
