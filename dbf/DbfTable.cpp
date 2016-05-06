//
// Created by Chris Richards on 27/04/2016.
//

#include <boost/filesystem.hpp>
#include "DbfTable.h"
#include "DbfMemoDbase3.h"
#include "DbfMemoDbase4.h"
#include "DbfMemoFoxpro.h"

DbfTable::DbfTable() {

}

DbfTable::DbfTable(const std::string& filename, bool skip_deleted_records)
    : skip_deleted_records_(skip_deleted_records) {
    open(filename);
}

DbfTable::~DbfTable() {
    if (file_.is_open()) {
        file_.close();
    }
}

void DbfTable::open(const std::string& filename) {
    filename_ = filename;
    file_.open(filename, std::ios::binary | std::ios::in);
    init();
}

void DbfTable::close() {
    file_.close();
}

void DbfTable::init() {
    header_ = DbfHeaderPtr(new DbfHeader(file_));
    read_columns(file_);

    if (header_->is_foxpro()) {
        // skip database container (263 bytes)
        // file_.seekg(263, std::ios_base::cur);
    }

    std::string f(memo_filename());
    if (!f.empty()) {
        memo_ = create_memo(f);
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
    std::string f(memo_filename());
    return !f.empty();
}

std::string DbfTable::memo_filename() const {
    boost::filesystem::path dbf_path(filename_);

    boost::filesystem::path memo_path;

    boost::filesystem::directory_iterator end;
    for (boost::filesystem::directory_iterator it(dbf_path.parent_path()); it != end; ++it) {
        if (!boost::filesystem::is_regular_file( it->status())) {
            continue;
        }

        boost::filesystem::path path = it->path();
        if ((path == dbf_path) || (path.stem() != dbf_path.stem())){
            continue;
        }

        boost::filesystem::path ext = path.extension();
        if ((ext == ".fpt") || (ext == ".FPT") ||
            (ext == ".dbt") || (ext == ".DBT")) {
            memo_path = path;
            break;
        }
    }

    return memo_path.string();
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
    DbfRecordPtr record = DbfRecordPtr(new DbfRecord(this, memo_));
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

DbfMemoPtr DbfTable::create_memo(const std::string &filename) const {
    DbfMemoPtr memo;

    if (header_->is_foxpro()) {
        memo = DbfMemoPtr(new DbfMemoFoxpro(filename));
    }
    else {
        int version = header_->version();
        if (version == 0x83) {
            memo = DbfMemoPtr(new DbfMemoDbase3(filename));
        }
        else {
            memo = DbfMemoPtr(new DbfMemoDbase4(filename));
        }
    }

    return memo;
}