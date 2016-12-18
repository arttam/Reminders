#ifndef RDB_H
#define RDB_H

#include <string>
#include <vector>
#include <iostream>

#include "entry.h"

class RDB
{
    std::string lastError_;
    std::vector<std::string> fields_;
    std::vector<Entry> entries_;

public:
    RDB();
    bool readDB(std::string data);

    std::string getLastError() const { return lastError_; }

    bool getEntry(const std::string name, Entry& entry);
    bool setEntry(Entry entry);
    bool setEntry(const std::string& name, const std::string& field, const std::string& value);

    std::vector<std::string> getNames();
    std::vector<std::string>& getFields();
    size_t getFieldsCount() { return fields_.size(); }
    std::vector<Entry>& getAllEntries() { return entries_; }

    bool saveDB(std::ostream& os);
    bool deleteEntry(const std::string name);
};

#endif // RDB_H
