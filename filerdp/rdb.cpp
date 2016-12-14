#include "rdb.h"
#include <iostream>
#include <algorithm>
#include <regex>

RDB::RDB(const char* path):rdbPath_(path)
{

}

bool RDB::parse()
{
    // TODO: Replace with something meaningful
    if (rdbPath_.empty()) {
        rdbPath_.assign("/home/art/QtProjects/reminder-db/rdb");
    }

    fileHandler _fh(rdbPath_.c_str());
    if (!_fh) {
        std::cerr << "Cannot open file" << rdbPath_ << std::endl;
        return false;
    }

    std::string _dbData(_fh.getContents());

    std::regex _rEOL("\\n");
    std::sregex_token_iterator _dLine(_dbData.begin(), _dbData.end(), _rEOL, -1);

    // First line - fields names
    Entry _fields(*_dLine++);
    fields_ = _fields.getValues();
    while (_dLine != std::sregex_token_iterator()) {
        entries_.emplace_back(*_dLine++);
    }
    return true;
}

bool RDB::getEntry(const std::string name, Entry& entry)
{
    std::vector<Entry>::iterator _findNameIt = std::find_if(entries_.begin(), entries_.end(), [&name](Entry& entry){ return (entry.getValue(0).compare(name) == 0); });
    if (_findNameIt == entries_.end()) {
        return false;
    }
    entry = *_findNameIt;
    return true;
}

bool RDB::setEntry(Entry entry)
{
    std::vector<Entry>::iterator _findNameIt = std::find_if(entries_.begin(), entries_.end(), [&entry](Entry& element){ return (element.getValue(0).compare(entry.getValue(0)) == 0); });
    if (_findNameIt == entries_.end()) {
        entries_.emplace_back(entry);
        return true;
    }
    _findNameIt->setEntry(entry);
    return true;
}

bool RDB::setEntry(const std::string& name, const std::string& field, const std::string& value)
{
    std::vector<Entry>::iterator _findNameIt = std::find_if(entries_.begin(), entries_.end(), [&name](Entry& element){ return (element.getValue(0).compare(name) == 0); });
    if (_findNameIt == entries_.end()) {
        lastError_.assign("Entry: ").append(name).append(" not found");
        return false;
    }

    std::vector<std::string>::iterator _findFieldIt = std::find(fields_.begin(), fields_.end(), field);
    if (_findFieldIt == fields_.end()) {
        lastError_.assign("Field: ").append(field).append(" not found");
        return false;
    }

    return _findNameIt->setValue(std::distance(fields_.begin(), _findFieldIt), value);
}

std::vector<std::string> RDB::getNames()
{
    std::vector<std::string> _names;
    std::transform(entries_.begin(), entries_.end(), std::back_inserter(_names), [](Entry& entry){ return entry.getValue(0); });

    return _names;
}

std::vector<std::string>& RDB::getFields()
{
   return fields_;
}

bool RDB::saveDB()
{
    fileHandler _fh(rdbPath_.c_str(), true);
    if (!_fh) {
        return false;
    }

    std::ostream& _fos = _fh.getStream();
    std::copy(fields_.begin(), fields_.end(), std::ostream_iterator<std::string>(_fos, ":"));
    _fos << std::endl;
    std::copy(entries_.begin(), entries_.end(), std::ostream_iterator<Entry>(_fos, "\n"));
    /*
    for(auto &entry: entries_) {
        std::cout << "Writing as '" << entry << "'" << std::endl;
        _fos << entry;
        _fos << std::endl;
    }
    */

    return true;
}

bool RDB::deleteEntry(const std::string name)
{
    std::vector<Entry>::iterator _findNameIt = std::find_if(entries_.begin(), entries_.end(), [&name](Entry& entry){ return (entry.getValue(0).compare(name) == 0); });
    if (_findNameIt == entries_.end()) {
        return false;
    }

    entries_.erase(_findNameIt);
    return true;
}
