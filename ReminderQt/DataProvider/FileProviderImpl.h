//
// Created by art on 15/07/16.
//

#ifndef REMINDER_FILEPROVIDERIMPL_H
#define REMINDER_FILEPROVIDERIMPL_H
#include <string>
#include <list>
#include <map>
#include <iostream>


#include "DataEntry.h"
#include "ISTLProvider.h"

class FileProviderImpl : public ISTLProvider {

    Keys keys_;
    Items items_;

    std::string source_;

public:
    FileProviderImpl(const std::string& source): source_{source} {}
    virtual ~FileProviderImpl() = default;

    bool read() override ;
    bool save() override;

    std::list<std::string>& getKeys() override ;
    const EntryStruct *getListItem(const std::string& key) const override ;
    bool setListItem(const EntryStruct &item) override;
    bool removeListItem(const std::string& key) override;
};


#endif //REMINDER_FILEPROVIDERIMPL_H
