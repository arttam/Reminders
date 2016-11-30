#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

#include "session.h"

Session::Session(tcp::socket socket, RDB& rdb)
    : reFwdSlash_{"/"}
    , socket_(std::move(socket))
    , rdb_(rdb)
{
}

void Session::do_read()
{
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(request_, 8192),
        [this, self](boost::system::error_code ec, std::size_t len)
        {
            if (!ec)  {
                parseRequest(len);
            }
        }
    );
}

void Session::do_write(std::size_t len)
{
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(response_, len),
        [this, self](boost::system::error_code ec, std::size_t)
        {
            if (!ec) {
                do_read();
            }
        }
    );
}

void Session::start()
{
    do_read();
}

void Session::parseRequest(std::size_t len)
{
    std::string _cmd;
    std::copy_if(request_, request_ + len, std::back_inserter(_cmd),
        [](char ch) { return (ch != '\r' && ch != '\n'); }
    );

    response_.clear();

    std::vector<std::string> _request;
    std::copy(std::sregex_token_iterator(_cmd.begin(), _cmd.end(), reFwdSlash_, -1),
              std::sregex_token_iterator(),
              std::back_inserter(_request));

    if (_request.empty()) {
        // No valid command found - leaving
        _cmd.insert(0, "ERROR: Not valid query: ");
        std::copy(_cmd.begin(), _cmd.end(), std::back_inserter(response_));
        do_write(response_.size());
        return;
    }

    // As we starting with forward slash ...
    if (_request.at(0).empty()) {
        _request.erase(_request.begin());
    }

    if (_request.at(0).compare("get") == 0) {
        // Move iterator to field name
        if (_request.size() < 2) {
            _cmd.insert(0, "ERROR: Unrecognized format: ");
            std::copy(_cmd.begin(), _cmd.end(), std::back_inserter(response_));
            do_write(response_.size());
            return;
        }
        Entry _response;
        std::string _getParm(_request.at(1));
        //if (rdb_.getEntry(*_cmdPartIt, _response)) {
        if (rdb_.getEntry(_getParm, _response)) {
            std::stringstream _sstr;
            _sstr << _response;
            std::copy(_sstr.str().begin(), _sstr.str().end(), std::back_inserter(response_));
            do_write(response_.size());
            return;
        }
        else {
            _cmd.insert(0, "ERROR: Not found: ");
            std::copy(_cmd.begin(), _cmd.end(), std::back_inserter(response_));
            do_write(response_.size());
            return;
        }
    }
    else if (_request.at(0).compare("set") == 0) {

    }
    else if (_request.at(0).compare("fields") == 0) {

    }
    else if (_request.at(0).compare("all") == 0) {

    }
    else {
        _cmd.insert(0, "ERROR: Unrecognized command: ");
        std::copy(_cmd.begin(), _cmd.end(), std::back_inserter(response_));
        do_write(response_.size());
        return;
    }


    //////

    std::cout << "Got command: " << _cmd << std::endl;

    std::string _tmpGet{"GET"};
    std::string _tmpSet{"SET"};
    std::string _tmpList{"LIST"};
    std::string _notFound{"NOT FOUND"};

    std::string& _strOut = _notFound;
    if (_cmd.compare("get") == 0) {
        _strOut = _tmpGet;
        //std::copy(_tmpGet.begin(), _tmpGet.end(), std::back_inserter(response_));
    }
    else if (_cmd.compare("set") == 0) {
        _strOut = _tmpSet;
        //std::copy(_tmpSet.begin(), _tmpSet.end(), std::back_inserter(response_));
    }
    else if (_cmd.compare("list") == 0) {
        _strOut = _tmpList;
        //std::copy(_tmpList.begin(), _tmpList.end(), std::back_inserter(response_));
    }

    std::copy(_strOut.begin(), _strOut.end(), std::back_inserter(response_));
    response_.push_back('\r');
    response_.push_back('\n');
    do_write(response_.size());
}


