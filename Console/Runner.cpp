//
// Created by art on 25/10/15.
//
#include <string>
#include <sstream>
#include <iostream>

// Silent password stuff
#include <termios.h>

#include "Runner.h"

int getPassword(std::string& pwd)
{
    struct termios oflags, nflags;
    char password[64];

/* disabling echo */
    tcgetattr(fileno(stdin), &oflags);
    nflags = oflags;
    nflags.c_lflag &= ~ECHO;
    nflags.c_lflag |= ECHONL;

    if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0) {
        perror("tcsetattr");
        return EXIT_FAILURE; // 1
    }

    printf("password: ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1] = 0;
    pwd.assign(password);
    printf("you typed '%s'\n", password);

/* restore terminal */
    if (tcsetattr(fileno(stdin), TCSANOW, &oflags) != 0) {
        perror("tcsetattr");
        return EXIT_FAILURE; // 1
    }

    return EXIT_SUCCESS; // 0
}

Runner::Runner()
    : commands_{
        {"local", {"local function details here", &Runner::local}},
        {"help", {"Supported functions list", &Runner::help}},
        {"ls", {"ls detailed description goes here", &Runner::ls}},
        {"add", {"add new logins and/or sites", &Runner::add}},
        {"rm", {"remove login and/or site", &Runner::rm}},
        {"check", {"check password for login", &Runner::check}},
        {"update", {"update login and/or site", &Runner::update}},
        {"quit", {"Quit application", &Runner::quit}}
    }
{
}

bool Runner::ls(std::vector<std::string>& params)
{
    if (params.size() < 2) {
        std::cout << "List type is required, cannot proceed any further" << std::endl;
        return false;
    }

    std::cout << "Trying to get list for: "  << params.at(1) << std::endl;
    if (!dbHandler_->list(params.at(1))) {
        std::cerr << "Error occurred while trying to get list: " << params.at(1) << std::endl;
        for(auto _error : dbHandler_->getErrors()) {
            std::cerr << _error << std::endl;
        }

        // Resetting errors description vector
        dbHandler_->clearErrors();
    }
    // True returned for fatal errors only ....
    return  false;
}

bool Runner::help(std::vector<std::string>&)
{
    std::cout << "auto generated help here" << std::endl;
    for (auto &cmd : commands_)
        std::cout << "\t " << cmd.first << " - " << cmd.second.first << std::endl;

    return false;
}

bool Runner::quit(std::vector<std::string>&)
{
    // TODO Maybe some cleanup, if needed here
    return true;
}

// Trial
bool Runner::local(std::vector<std::string> &)
{
    std::cout << "Local implementation here" << std::endl;
    return false;
}

bool Runner::run(const char *dbPath)
{
    dbHandler_.reset(new DBHandler(dbPath));
    if (!dbHandler_->openDB()) {
        std::cerr << "Cannot open database" << std::endl;
        return false;
    }

    RunnerFPtr fp;
    std::function<bool(std::vector<std::string>&)> _helper = std::bind(&Runner::help, this, std::placeholders::_1);

    bool _runnerResult{true};
    std::string _command;
    std::vector<std::string> _cmdParts;

    while(true) {
        std::cout << "> ";
        std::getline(std::cin, _command);
        _cmdParts.clear();

        LocCommandIt _cmd;
        if (_command.empty()) {
            _helper(_cmdParts);
            continue;
        }

        std::istringstream _iss(_command);
        std::copy(std::istream_iterator<std::string>(_iss), std::istream_iterator<std::string>(), std::back_inserter(_cmdParts));

        _cmd = commands_.find(_cmdParts.at(0));
        if (_cmd == commands_.end()) {
            std::cerr << "Command '" << _cmdParts.at(0) << "' not supported" << std::endl;
            _helper(_cmdParts);
            continue;
        }

        std::cout << "Processing command: " << _cmd->first << std::endl;
        fp = _cmd->second.second;
        if ((this->*fp)(_cmdParts)) {
            // Quit return received, leaving
            break;
        }
   }
    return _runnerResult;
}

std::vector<std::string>& Runner::getErrors() {
    return dbHandler_->getErrors();
}

bool Runner::add(std::vector<std::string> &params) {
    if (params.size() < 2) {
        std::cout << "Add requires type and params, cannot proceed any further" << std::endl;
        return false;
    }

    std::cout << "Trying to add entry as: "  << params.at(1) << std::endl;
    if (!dbHandler_->add(params.at(1))) {
        std::cerr << "Error occurred while trying to add entry: " << params.at(1) << std::endl;
        for(auto _error : dbHandler_->getErrors()) {
            std::cerr << _error << std::endl;
        }

        // Resetting errors description vector
        dbHandler_->clearErrors();
    }
    // True returned for fatal errors only ....
    return  false;
}

bool Runner::rm(std::vector<std::string> &params) {
    if (params.size() < 2) {
        std::cout << "Remove requires type and params, cannot proceed any further" << std::endl;
        return false;
    }

    std::cout << "Trying to remove entry as: "  << params.at(1) << std::endl;
    if (!dbHandler_->rm(params.at(1))) {
        std::cerr << "Error occurred while trying to remove entry: " << params.at(1) << std::endl;
        for(auto _error : dbHandler_->getErrors()) {
            std::cerr << _error << std::endl;
        }

        // Resetting errors description vector
        dbHandler_->clearErrors();
    }
    // True returned for fatal errors only ....
    return false;
}

bool Runner::check(std::vector<std::string> &params) {
    if (params.size() < 2) {
        std::cout << "Check requires type and params, cannot proceed any further" << std::endl;
        return false;
    }

    std::cout << "Trying to check entry as: "  << params.at(1) << std::endl;
    if (!dbHandler_->check(params.at(1))) {
        std::cerr << "Error occurred while trying to check entry: " << params.at(1) << std::endl;
        for(auto _error : dbHandler_->getErrors()) {
            std::cerr << _error << std::endl;
        }

        // Resetting errors description vector
        dbHandler_->clearErrors();
    }
    // True returned for fatal errors only ....
    return false;
}

bool Runner::update(std::vector<std::string> &params) {
    if (params.size() < 2) {
        std::cout << "Update requires type and params, cannot proceed any further" << std::endl;
        return false;
    }

    std::cout << "Trying to update entry as: "  << params.at(1) << std::endl;
    if (!dbHandler_->update(params.at(1))) {
        std::cerr << "Error occurred while trying to update entry: " << params.at(1) << std::endl;
        for(auto _error : dbHandler_->getErrors()) {
            std::cerr << _error << std::endl;
        }

        // Resetting errors description vector
        dbHandler_->clearErrors();
    }
    // True returned for fatal errors only ....
    return false;
}
