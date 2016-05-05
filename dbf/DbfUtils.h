//
// Created by Chris Richards on 29/04/2016.
//

#ifndef DBF2CSV_DBFUTILS_H
#define DBF2CSV_DBFUTILS_H

#include <istream>

template <class T>
void read_raw(std::istream& stream, T& value)
{
    stream.read(reinterpret_cast<char*>(&value), sizeof(value));
}

// explicit template argument read
template <class T>
T read_raw(std::istream& stream)
{
    T value;
    read_raw(stream, value);
    return value;
}

#endif //DBF2CSV_DBFUTILS_H
