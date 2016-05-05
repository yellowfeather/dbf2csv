//
// Created by Chris Richards on 27/04/2016.
//

#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "DbfHeader.h"
#include "DbfUtils.h"

const int kDbfHeaderSize = 32;


DbfHeader::DbfHeader(std::ifstream &file) {
    read(file);
}

void DbfHeader::read(std::ifstream &file) {
    version_ = read_raw<uint8_t>(file);

    int year = read_raw<uint8_t>(file);
    int month = read_raw<uint8_t>(file);
    int day = read_raw<uint8_t>(file);

    std::stringstream s1;
    s1 << std::setfill('0') << std::setw(2) << day;
    s1 << std::setfill('0') << std::setw(2) << month;
    s1 << std::setfill('0') << std::setw(2) << year;
    updated_at_ = s1.str();

    record_count_ = uint32_t(read_raw<uint8_t>(file) | (read_raw<uint8_t>(file) << 8) | (read_raw<uint8_t>(file) << 16) | (read_raw<uint8_t>(file) << 24));
    header_length_ = uint16_t(read_raw<uint8_t>(file) | (read_raw<uint8_t>(file) << 8));
    record_length_ = uint16_t(read_raw<uint8_t>(file) | (read_raw<uint8_t>(file) << 8));

    // skip the next 20 bytes
    file.seekg(20, std::ios_base::cur);
}

int DbfHeader::version() const {
    return version_;
}

std::string DbfHeader::version_description() const {
    std::string description;

    switch (version_) {
        case 0x02: description = "FoxBase"; break;
        case 0x03: description = "dBase III without memo file"; break;
        case 0x04: description = "dBase IV without memo file"; break;
        case 0x05: description = "dBase V without memo file"; break;
        case 0x07: description = "Visual Objects 1.x"; break;
        case 0x30: description = "Visual FoxPro"; break;
        case 0x31: description = "Visual FoxPro with AutoIncrement field"; break;
        case 0x43: description = "dBASE IV SQL table files, no memo"; break;
        case 0x63: description = "dBASE IV SQL system files, no memo"; break;
        case 0x7b: description = "dBase IV with memo file"; break;
        case 0x83: description = "dBase III with memo file"; break;
        case 0x87: description = "Visual Objects 1.x with memo file"; break;
        case 0x8b: description = "dBase IV with memo file"; break;
        case 0x8e: description = "dBase IV with SQL table"; break;
        case 0xcb: description = "dBASE IV SQL table files, with memo"; break;
        case 0xf5: description = "FoxPro with memo file"; break;
        case 0xfb: description = "FoxPro without memo file"; break;
        default:
            description = "Unknown";
            break;
    }

    return description;
}

bool DbfHeader::is_foxpro() const {
    return version_ == 0x30 || version_ == 0x31 || version_ == 0xf5 || version_ == 0xfb;
}

std::string DbfHeader::updated_at() const {
    return updated_at_;
}

int DbfHeader::header_length() const {
    return header_length_;
}

int DbfHeader::record_length() const {
    return record_length_;
}

long DbfHeader::record_count() const {
    return record_count_;
}




