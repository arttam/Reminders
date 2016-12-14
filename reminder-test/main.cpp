#include <iostream>

// Temporary for text
#include <string>
#include <algorithm>
#include <iterator>
#include <regex>

//#include "rdb.h"
#include "rdb.h"

int main(int argc, char *argv[])
{
    char defaultPath[] = "/home/art/git/Reminders/reminder-test/rdb";
    char *rdbPath = defaultPath;

    if (argc > 1) {
        rdbPath = argv[1];
    }

    RDB _rdb(rdbPath);
    if (!_rdb.parse()) {
        std::cerr << "Error while parsing: " << rdbPath << std::endl;
        return 1;
    }

    std::vector<std::string> _fields(_rdb.getFields());

    Entry _newOne("Edit:TestOverwrite:Entry:N/A:somepwd:Some Description");
    _rdb.setEntry(_newOne);

    _rdb.setEntry("Edit", "Type", "SetField3");

    if (_rdb.saveDB()) {
        std::cout << "Saved successfully" << std::endl;
    }
    else {
        std::cerr << "Failed to save changes" << std::endl;
    }


    return 0;
}
