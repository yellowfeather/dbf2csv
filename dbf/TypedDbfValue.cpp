//
// Created by Chris Richards on 03/05/2016.
//

#include "DbfUtils.h"
#include "TypedDbfValue.h"

template <>
void TypedDbfValue<int>::read(std::istream &stream) {
    buffer_read(stream);
    std::string s(buffer_as_string());
    if (s.empty()) {
        value_ = boost::none;
    }
    else {
        value_ = std::stoi(s);
    }
}

template <>
void TypedDbfValue<float>::read(std::istream &stream) {
    buffer_read(stream);
    std::string s(buffer_as_string());
    if (s.empty()) {
        value_ = boost::none;
    }
    else {
        value_ = std::stof(s);
    }
}

template <>
void TypedDbfValue<long>::read(std::istream &stream) {
    if (stream.peek() == '\0') {
        buffer_read(stream);
        value_ = boost::none;
    }
    else {
        value_ = read_raw<uint32_t>(stream);
    }
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
    if (memo_) {
        int start_block = read_raw<uint32_t>(stream);
        value_ = memo_->get(start_block);
    }
    else {
        buffer_read(stream);
        std::string s(buffer_as_string());

        if (s.empty()) {
            value_ = boost::none;
        }
        else {
            value_ = s;
        }
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
        // TODO: escape double quotes ',', '"', '\r', '\n'
        // TODO: enclose in double quotes if required
        // TODO: sanitize ???
        os << value;
    }
}

