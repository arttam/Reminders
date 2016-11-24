#include <iostream>
#include "dbhandler.h"

static const char EmptyDBCheck[] = "select count(name) from sqlite_master where type='table'";

DBHandler::DBHandler(const char *dbPath)
    : dbPath_(dbPath ? dbPath : dbpath)
    , listCommands_{
        {"-u", "select alias from logins"},
        {"-m", "select md5 from logins"},
        {"-U", "select id, alias, hint, md5 from logins"},
        {"-s", "select site, username from sites"},
        {"-S", "select s.site, s.username, l.alias, l.hint from sites s inner join logins l on s.login_id = l.id"},
        {"-h", "ls keys:\r\n  -u  login aliases\r\n  -m  md5\r\n  -U  all user information\r\n  -s  site and username\r\n  -S  site and logins linked\r\n"}
      }
    , addCommands_ {
        {"-u", "insert into logins (id, alias, hint, md5) values ((select max(id)+1 from logins), '%a', '%h', '%m')"},
        {"-s", "insert into sites (id, username, site, login_id) values ((select max(id)+1 from sites), '%u', '%s', %i)"},
        {"-h", "add keys:\r\n  -u  Add new login (-a: alias; -h: hint; -m: md5)\r\n  -s  Add new site (-u: username, -s: site, -l: logins id)"}
      }
    , rmCommands_ {
        {"-u", "delete from logins where id = %i"} ,
        {"-s", "delete from sites where id = %i"},
        {"-h", "remove entries:\r\n  -u  Remove login (-i: login id)\r\n  -s  Remove site (-s: site id)"}
      }
    , updateCommands_ {
        {"-u", "update logins "},
        {"-s", "update sites "}
      }
    , checkCommands_ {
        {"-a", "check by alias"},
        {"-l", "check by login"}
      }
{
    std::cout << "Initializing" << std::endl;
}

bool DBHandler::openDB()
{
    openRC_ = sqlite3_open(dbPath_, &db_);
    if (openRC_) {
        std::string _err{"Failed to open database: "};
        _err.append(dbPath_);
        errors_.push_back(_err);
        sqlite3_close(db_);
        db_ = nullptr;
        return false;
    }

    std::cout << "Opened database fine" << std::endl;
    sqlite3_stmt *_emptyCheck;
    int _lRes = sqlite3_prepare_v2(db_, EmptyDBCheck, -1, &_emptyCheck, NULL);
    if(_lRes) {
        std::string _err{"Failed to preapare empty database check statement: "};
        _err.append(std::to_string(_lRes));
        errors_.push_back(_err);
        return false;
    }

    int _tablesCount = -1;
    switch(sqlite3_step(_emptyCheck)) {
        case SQLITE_ROW:
            _tablesCount = sqlite3_column_int(_emptyCheck, 0);
            break;
        default:
            break;
    }

    if (!_tablesCount)
        errors_.push_back("Database does not have any tables, leaving");

    sqlite3_finalize(_emptyCheck);

    return (_tablesCount > 0);
}

DBHandler::~DBHandler()
{
    std::cout << "Calling destructor" << std::endl;
    if (db_) {
        std::cout << "Closing database ..." << std::endl;
        sqlite3_close(db_);
    }
}

bool DBHandler::list(std::string& type)
{
    ListCommandIt _lType;
    if (!checkMapForCommand(type, listCommands_, "Error - cannot find list command: ", _lType))
        return false;

    sqlite3_stmt *_stmt;
    int _lRes = sqlite3_prepare_v2(db_, _lType->second.c_str(), -1, &_stmt, NULL);
    if (_lRes) {
        std::string _err{"Failed to prepare list statement: "};
        _err.append(std::to_string(_lRes));
        errors_.push_back(_err);
        errors_.push_back(_lType->second.insert(0, "Statement which failed: "));
        return false;
    }

    bool _continue = true;
    bool _needHeader = true;
    while(_continue) {
        switch (sqlite3_step(_stmt)) {
            case SQLITE_ROW:
                {
                    if (_needHeader) {
                        for(int colNr=0; colNr < sqlite3_column_count(_stmt); ++colNr)
                            std::cout << "| " << sqlite3_column_name(_stmt, colNr) << " ";
                        std::cout << std::endl << std::string(80, '=') << std::endl;
                        _needHeader = false;
                    }
                    for(int colNr=0; colNr < sqlite3_column_count(_stmt); ++colNr)
                        std::cout << "| " << (char *) sqlite3_column_text(_stmt, colNr);
                    std::cout << std::endl;
                }
                break;
            case SQLITE_DONE:
                _continue = false;
                break;
            default:
                _continue = false;
                break;
        }
    }
    sqlite3_finalize(_stmt);

    return true;
}

void DBHandler::clearErrors() {
    errors_.clear();
}

bool DBHandler::add(std::string &cmd) {
    ListCommandIt _aType;
    if (!checkMapForCommand(cmd, addCommands_, "Error - cannot find add command: ", _aType))
        return false;

    if (_aType->first.compare("-h") == 0)
        return true;

    return true;
}

bool DBHandler::rm(std::string &cmd) {
    ListCommandIt _rmType;
    if (!checkMapForCommand(cmd, rmCommands_, "Error - cannot find remove command: ", _rmType))
        return false;

    if (_rmType->first.compare("-h") == 0)
        return true;

    return true;
}

bool DBHandler::update(std::string &cmd) {
    ListCommandIt _uType;
    if (!checkMapForCommand(cmd, updateCommands_, "Error - cannot find remove command: ", _uType))
        return false;

    if (_uType->first.compare("-h") == 0)
        return true;

    return true;
}

bool DBHandler::check(std::string &cmd) {
    ListCommandIt _cType;
    if (!checkMapForCommand(cmd, checkCommands_, "Error - cannot find remove command: ", _cType))
        return false;

    if (_cType->first.compare("-h") == 0)
        return true;

    return true;
}

bool DBHandler::checkMapForCommand(std::string &cmd, DBHandler::ListCommands &cmdMap, std::string errorText, ListCommandIt &cmdIt) {
    cmdIt = cmdMap.find(cmd);
    if (cmdIt == cmdMap.end()) {
        errorText.append(cmd);
        errors_.push_back(errorText);
        return false;
    }

    if (cmdIt->first.compare("-h") == 0)
        std::cout << cmdIt->second << std::endl;
    return true;
}
