//
// Created by art on 15/07/16.
//

#ifndef REMINDER_DATAENTRY_H
#define REMINDER_DATAENTRY_H

#include <string>

struct EntryStruct
{
    std::string key;
    std::string login;
    std::string hint;
    std::string remarks;
};

std::ostream& operator<<(std::ostream& output, const EntryStruct& es);

#endif //REMINDER_DATAENTRY_H
