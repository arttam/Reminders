#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

#include "session.h"

Session::Session(tcp::socket socket, RDB& rdb, std::string& rdbPath)
    : reFwdSlash_{"/"}
    , socket_(std::move(socket))
    , rdbPath_(rdbPath)
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

void Session::do_write()
{
    // Every respnse should be finished with empty line
    // i.e. only containing \r\n sequence
    response_.push_back('\r');
    response_.push_back('\n');

    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(response_, response_.size()),
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
        do_write();
        return;
    }

    auto &e_response_ = response_;
    auto buildError = [&e_response_](const char *errMsg) -> void
    {
        std::string _err(errMsg);
        std::copy(_err.begin(), _err.end(), std::back_inserter(e_response_));
        e_response_.push_back('\r');
        e_response_.push_back('\n');
    };

    // As we starting with forward slash ...
    if (_request.at(0).empty()) {
        _request.erase(_request.begin());
    }

    if (_request.empty()) {
        // No valid command found - leaving
        _cmd.insert(0, "ERROR: Not valid query: ");
        std::copy(_cmd.begin(), _cmd.end(), std::back_inserter(response_));
        do_write();
        return;
    }

    if (_request.at(0).compare("get") == 0) {
        if (_request.size() < 2) {
            // Get all entries
            std::vector<Entry>& _entries = rdb_.getAllEntries();
            std::stringstream _sstr;
            for(auto &entry: _entries) {
                entry >> response_;
                response_.push_back('\r');
                response_.push_back('\n');
            }
        }
        else {
            Entry _response;
            std::string _getParm(_request.at(1));
            if (rdb_.getEntry(_getParm, _response)) {
                _response >> response_;
            }
            else {
                _cmd.insert(0, "ERROR: Not found: ");
                std::copy(_cmd.begin(), _cmd.end(), std::back_inserter(response_));
            }
        }
    }
    else if (_request.at(0).compare("set") == 0) {
        if (_request.size() == 2) {
            // Entire entry should present as 2nd parameter
            // TODO: Validation should be here !!!
            Entry _entry(_request.at(1));
            if (_entry.getCount() != rdb_.getFieldsCount()) {
                buildError("Invalid number of fileds");
            }
            else {
                if (!rdb_.setEntry(_entry)) {
                    std::string _err{"Filed to set Entry: "};
                    _err.append(rdb_.getLastError());
                    std::copy(_err.begin(), _err.end(), std::back_inserter(response_));
                }
                else {
                    buildError("SUCCESS");
                }
            }
        }
        else if (_request.size() == 4) {
            if (rdb_.setEntry(_request.at(1), _request.at(2), _request.at(3))) {
                buildError("SUCCESS");
            }
            else {
                std::string _err{"Failed to set value: "};
                _err.append(rdb_.getLastError());
                std::copy(_err.begin(), _err.end(), std::back_inserter(response_));
            }
        }
        else {
            buildError("ERROR: set requires either 2 or 4 parameters");
        }
    }
    else if (_request.at(0).compare("delete") == 0) {
        if (rdb_.deleteEntry(_request.at(1))) {
            buildError("SUCCESS");
        }
        else {
            std::string _err{"ERROR: Failed to delete "};
            _err.append(_request.at(1));
            _err.append("; ");
            _err.append(rdb_.getLastError());
            buildError(_err.c_str());
        }
    }
    else if (_request.at(0).compare("fields") == 0) {
        std::vector<std::string>& _fields = rdb_.getFields();
        for(auto &field: _fields) {
            if (!response_.empty())
                response_.push_back(',');

            std::copy(field.begin(), field.end(), std::back_inserter(response_));
        }
    }
    else if (_request.at(0).compare("commit") == 0) {

        fileHandler _fh(rdbPath_.c_str(), true);
        if (!_fh) {
            buildError("Failed to open db file for writting");
        }
        else {
            if (rdb_.saveDB(_fh.getStream())) {
                buildError("SUCCESS");
            }
            else {
                std::string _err{"Failed to preserve DB: "};
                _err.append(rdb_.getLastError());
                std::copy(_err.begin(), _err.end(), std::back_inserter(response_));
            }
        }
    }
    else {
        _cmd.insert(0, "ERROR: Unrecognized command: ");
        std::copy(_cmd.begin(), _cmd.end(), std::back_inserter(response_));
    }
    response_.push_back('\r');
    response_.push_back('\n');
    do_write();
}


