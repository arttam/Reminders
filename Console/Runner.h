//
// Created by art on 25/10/15.
//

#ifndef HELLO_CLION_RUNNER_H
#define HELLO_CLION_RUNNER_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "dbhandler.h"

class Runner {
public:
    // Local commands
    // Note C++11 alias declaration instead of typedef
    using RunnerFPtr   = bool (Runner::*)(std::vector<std::string>&);
    using LocCommand   = std::pair<const std::string, RunnerFPtr>;
    using LocCommands  = std::map<const std::string, Runner::LocCommand>;
    using LocCommandIt =  LocCommands::iterator;

    // execution
    bool ls(std::vector<std::string>&);
    bool help(std::vector<std::string>&);
    bool quit(std::vector<std::string>&);
    bool local(std::vector<std::string>&);
    bool add(std::vector<std::string>&);
    bool rm(std::vector<std::string>&);
    bool check(std::vector<std::string>&);
    bool update(std::vector<std::string>&);

    Runner();
    virtual ~Runner() { }

    bool run(const char *dbPath);
    std::vector<std::string>& getErrors();

private:
    LocCommands commands_;
    std::unique_ptr<DBHandler> dbHandler_;
};


#endif //HELLO_CLION_RUNNER_H

