#ifndef __UsesDBHandlerH__
#define __UsesDBHandlerH__
#include <sqlite3.h>
#include <string>
#include <map>
#include <vector>

const char dbpath[] = "/tmp/tryme.sqlite.db";

class DBHandler
{
public:
    typedef std::pair<std::string, std::string> ListCommand;
    typedef std::map<std::string, std::string> ListCommands;
    typedef std::map<std::string, std::string>::iterator ListCommandIt;

    DBHandler(const char *dbPath);
    virtual ~DBHandler();

    bool openDB();

    bool list(std::string& type);
    bool add(std::string& cmd);
    bool rm(std::string& cmd);
    bool update(std::string& cmd);
    bool check(std::string& cmd);

    std::vector<std::string>& getErrors() { return errors_; }
    void clearErrors();

private:
    DBHandler(DBHandler const&) = delete;
    DBHandler& operator=(DBHandler const&) = delete;


    ListCommands listCommands_;
    ListCommands addCommands_;
    ListCommands rmCommands_;
    ListCommands updateCommands_;
    ListCommands checkCommands_;

    // Helpers
    bool checkMapForCommand(std::string &cmd, ListCommands &cmdMap, std::string errorText, ListCommandIt& cmdIt);

    std::vector<std::string> errors_;

    int openRC_;
    const char *dbPath_;
    sqlite3 *db_;
};


#endif
