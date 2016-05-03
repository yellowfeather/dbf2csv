//
// Created by Chris Richards on 03/05/2016.
//

#include "TypedDbfValue.h"

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

