//
// Created by art on 20/09/16.
//

#ifndef REMINDER_DBPROVIDERIMPL_H
#define REMINDER_DBPROVIDERIMPL_H


#include <iostream>
#include "ISTLProvider.h"

class DbProviderImpl : public ISTLProvider {
    Keys keys_;
    Items items_;

    std::string source_;
public:
    DbProviderImpl(const std::string& source);
    virtual ~DbProviderImpl() = default;

    virtual bool read() override;
    virtual bool save() override;
    virtual std::list<std::string> &getKeys() override;
    virtual const EntryStruct *getListItem(const std::string &key) const override;
    virtual bool setListItem(const EntryStruct &item) override;
    virtual bool removeListItem(const std::string &key) override;
};

#endif //REMINDER_DBPROVIDERIMPL_H
