//
// Created by Chris Richards on 27/04/2016.
//

#include <iomanip>
#include <sstream>
#include "DbfColumn.h"
#include "DbfUtils.h"

const int kDbfFieldDescriptorSize = 32;

DbfColumn::DbfColumn(std::istream &stream, int index)
        : index_(index) {
    read(stream);
}

void DbfColumn::read(std::istream &stream) {
    name_.clear();
    name_.resize(10);

    stream.read(&name_[0], 11);

    size_t pos = name_.find('\0');
    if (pos != std::string::npos) {
        name_.erase(pos);
    }

    type_ = (DbfColumnType)read_raw<uint8_t>(stream);
    uint32_t address = read_raw<uint32_t>(stream);
    length_ = read_raw<uint8_t>(stream);
    decimal_ = read_raw<uint8_t>(stream);

    // skip the next 14 bytes
    stream.seekg(14, std::ios_base::cur);
}

int DbfColumn::index() const {
    return index_;
}

std::string DbfColumn::name() const {
    return name_;
}

DbfColumn::DbfColumnType DbfColumn::type() const {
    return type_;
}

int DbfColumn::length() const {
    return length_;
}

int DbfColumn::decimal() const {
    return decimal_;
}




