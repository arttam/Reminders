//
// Created by art on 20/09/16.
//

#ifndef REMINDER_ISTLPROVIDER_H
#define REMINDER_ISTLPROVIDER_H

#include <map>
#include <list>
#include "DataEntry.h"

struct ISTLProvider {
    using Keys  = std::list<std::string>;
    using Items = std::map<std::string, EntryStruct>;
    using CIt   = Items::const_iterator;
    using WIt   = Items::iterator;

    virtual ~ISTLProvider() = default;

    virtual bool read() = 0;
    virtual bool save() = 0;
    virtual std::list<std::string>& getKeys() = 0;
    virtual const EntryStruct *getListItem(const std::string& key) const = 0;
    virtual bool setListItem(const EntryStruct& item) = 0;
    virtual bool removeListItem(const std::string& key) = 0;
};

std::ostream& operator<<(std::ostream& output, const ISTLProvider::Items::value_type& item);

#endif //REMINDER_ISTLPROVIDER_H
