//
// Created by art on 21/09/16.
//
#include "ISTLProvider.h"

std::ostream& operator<<(std::ostream& output, const ISTLProvider::Items::value_type& item)
{
    output << item.second;
    return output;
}

