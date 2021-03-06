#ifndef RDB_H
#define RDB_H

#include <string>
#include <vector>
#include <iostream>

#include "filehandler.h"
#include "entry.h"

class RDB
{
    std::string rdbPath_;
    std::string lastError_;
    std::vector<std::string> fields_;
    std::vector<Entry> entries_;

public:
    RDB(const char* path);
    bool parse();

    std::string getLastError() const { return lastError_; }

    bool getEntry(const std::string name, Entry& entry);
    bool setEntry(Entry entry);
    bool setEntry(const std::string& name, const std::string& field, const std::string& value);

    std::vector<std::string> getNames();
    std::vector<std::string>& getFields();
    size_t getFieldsCount() { return fields_.size(); }
    std::vector<Entry>& getAllEntries() { return entries_; }

    bool saveDB();
    bool deleteEntry(const std::string name);
};

#endif // RDB_H
