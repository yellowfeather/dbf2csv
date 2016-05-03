//
// Created by Chris Richards on 03/05/2016.
//

#ifndef DBF2CSV_TYPEDDBFVALUE_H
#define DBF2CSV_TYPEDDBFVALUE_H

#include <cstdlib>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

#include "DbfColumn.h"
#include "DbfValue.h"

template <class T>
class TypedDbfValue : public DbfValue {
public:
    TypedDbfValue(DbfColumnPtr column);

    void read(std::istream &stream);

    void to_csv(std::ostream &os) const;

    boost::optional<T> value() const;

private:
    boost::optional<T> value_;
};

template <class T>
TypedDbfValue<T>::TypedDbfValue(DbfColumnPtr column)
    : DbfValue(column) {

}

template <>
void TypedDbfValue<int>::read(std::istream &stream) {
    buffer_read(stream);
    value_ = atoi(&buffer_[0]);
}

template <>
void TypedDbfValue<float>::read(std::istream &stream) {
    buffer_read(stream);
    value_ = atof(&buffer_[0]);
}

template <>
void TypedDbfValue<long>::read(std::istream &stream) {
    buffer_read(stream);
    value_ = atol(&buffer_[0]);
}

template <>
void TypedDbfValue<bool>::read(std::istream &stream) {
    buffer_read(stream);
    char ch = buffer_[0];
    if (ch == 'Y' || ch == 'y' || ch == 'T' || ch == 't') {
        value_ = true;
    }
    else if (ch == 'N' || ch == 'n' || ch == 'F' || ch == 'f') {
        value_ = false;
    }
    else {
        value_ = boost::none;
    }
}

template <>
void TypedDbfValue<std::string>::read(std::istream &stream) {
    buffer_read(stream);
    std::string s(&buffer_[0], buffer_.size());
    value_ = boost::algorithm::trim_right_copy(s);
}


template <class T>
void TypedDbfValue<T>::to_csv(std::ostream &os) const {
    if (value_ != boost::none) {
        os << *value_;
    }
}

template <>
void TypedDbfValue<float>::to_csv(std::ostream &os) const {
    if (value_ != boost::none) {
        os << *value_;
    }
}

template <>
void TypedDbfValue<bool>::to_csv(std::ostream &os) const {
    if (value_ != boost::none) {
        os << *value_;
    }
}

template <>
void TypedDbfValue<std::string>::to_csv(std::ostream &os) const {
    if (value_ != boost::none) {
        std::string value = *value_;
        // TODO: escape double quotes
        // TODO: enclose in double quotes if required
        // TODO: sanitize ???
        os << value;
    }
}

template <class T>
boost::optional<T> TypedDbfValue<T>::value() const {
    return value_;
}


#endif //DBF2CSV_TYPEDDBFVALUE_H
