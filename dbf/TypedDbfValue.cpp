//
// Created by Chris Richards on 03/05/2016.
//

#include <iomanip>
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
void TypedDbfValue<double>::read(std::istream &stream) {
    buffer_read(stream);
    std::string s(buffer_as_string());
    if (s.empty()) {
        value_ = boost::none;
    }
    else {
        value_ = std::stod(s);
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
void TypedDbfValue<double>::to_csv(std::ostream &os) const {
    if (value_ != boost::none) {
//        char *fmt = malloc(20);
//        sprintf(fmt, "%%%d.%df", column_->length(), column_->decimal());
//        fprintf(fp, fmt, *(double *)begin);
        os << std::fixed << std::setprecision(column_->decimal()) << *value_;
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
        std::string value(*value_);

        bool enclose_in_double_quotes = false;

        if (value.find("\"") != std::string::npos) {
            enclose_in_double_quotes = true;
            boost::replace_all(value, "\"", "\"\"");
        }
        else if (value.find_first_of(",\r\n") != std::string::npos) {
            enclose_in_double_quotes = true;
        }

        if (enclose_in_double_quotes) {
            os << '"' << value << '"';
        }
        else {
            os << value;
        }
    }
}

