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
    char defaultPath[] = "/home/art/QtProjects/reminder-db/rdb";
    char *rdbPath = defaultPath;

    if (argc > 1) {
        rdbPath = argv[1];
    }

    RDB _rdb(rdbPath);
    if (!_rdb.parse()) {
        std::cerr << "Error while parsing: " << rdbPath << std::endl;
        return 1;
    }

    std::cout << "Fields: " << std::endl;
    std::vector<std::string> _fields(_rdb.getFields());
    std::copy(_fields.begin(), _fields.end(), std::ostream_iterator<std::string>(std::cout, "\r\n"));

    std::cout << "Entries: " << std::endl;
    std::vector<std::string> _names(_rdb.getNames());
    std::copy(_names.begin(), _names.end(), std::ostream_iterator<std::string>(std::cout, "\r\n"));

    Entry _amazon;
    if (_rdb.getEntry("Amazon", _amazon)) {
        std::cout << "Login: " << _amazon.getValue(1) << std::endl;
    }
    else {
        std::cout << "Not found :-(" << std::endl;
    }

    Entry _newOne("Edit:Test:Entry:N/A:somepwd:Some Description");
    _rdb.setEntry(_newOne);

    _newOne.setValue(1, "EditedTest");
    _rdb.setEntry(_newOne);

    _rdb.deleteEntry("Edit");

    if (_rdb.saveDB()) {
        std::cout << "Saved successfully " << std::endl;
    }
    else {
        std::cout << "Failed to save DB" << std::endl;
    }

    return 0;
}
