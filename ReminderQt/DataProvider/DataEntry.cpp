#include <iostream>
#include "DataEntry.h"

std::ostream& operator<<(std::ostream& output, const EntryStruct& es)
{
    output << es.key << ":"
           << es.login << ":"
           << es.hint << ":"
           << es.remarks << std::endl;

    return output;
}
