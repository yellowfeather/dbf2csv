//
// Created by Chris Richards on 27/04/2016.
//

#include "DbfTable.h"

DbfTable::DbfTable() {

}

DbfTable::DbfTable(const std::string& filename, bool skip_deleted_records)
    : skip_deleted_records_(skip_deleted_records) {
    open(filename);
    init();
}

DbfTable::~DbfTable() {

}

void DbfTable::open(const std::string& filename) {
    file_.open(filename, std::ios::binary | std::ios::in);
}

void DbfTable::close() {
    file_.close();
}

void DbfTable::init() {
    header_ = DbfHeaderPtr(new DbfHeader(file_));
    read_columns(file_);

    if (header_->is_foxpro()) {
        // skip database container (263 bytes)
        file_.seekg(263, std::ios_base::cur);
    }
}

bool DbfTable::good() const {
    return file_.good();
}

bool DbfTable::skip_deleted_records() const {
    return skip_deleted_records_;
}

void DbfTable::skip_deleted_records(bool skip_deleted_records) {
    skip_deleted_records_ = skip_deleted_records;
}

bool DbfTable::has_memo_file() const {
    return false;
}

DbfHeaderPtr DbfTable::header() const {
    return header_;
}

std::vector<DbfColumnPtr> DbfTable::columns() {
    return columns_;
}

void DbfTable::get_record(DbfRecordPtr &record) {
    record->read(file_);
}


void DbfTable::to_csv(std::ostream &os) {
    // write csv header
    for (auto it = std::begin(columns_); it != std::end(columns_); ++it) {
        DbfColumnPtr column(*it);
        os << column->name();
        if (it != (std::end(columns_) - 1)) {
            os << ",";
        }
    }
    os << std::endl;

    // write csv lines
    DbfRecordPtr record = DbfRecordPtr(new DbfRecord(this));
    while (good()) {
        get_record(record);

        if (record->is_deleted() && skip_deleted_records_) {
            continue;
        }

        record->to_csv(os);
    }
}

void DbfTable::read_columns(std::istream &stream) {
    int index = 0;
    columns_.clear();

    while (stream.peek() != 0x0D) {
        DbfColumnPtr column = DbfColumnPtr(new DbfColumn(stream, index++));
        columns_.push_back(column);
    }

    char terminator = 0;
    stream.read(&terminator, 1);

// TODO: Assert terminator = 0x0d
}