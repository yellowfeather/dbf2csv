//
// Created by Chris Richards on 27/04/2016.
//

#include <boost/algorithm/string.hpp>
#include "DbfRecord.h"
#include "DbfTable.h"
#include "DbfUtils.h"

DbfRecord::DbfRecord(DbfTable *dbf_table, DbfMemoPtr memo)
{
    DbfHeaderPtr header = dbf_table->header();
    record_length_ = header->record_length();
    columns_ = dbf_table->columns();
    version_ = header->version();

    for (auto it = std::begin(columns_); it!=std::end(columns_); ++it) {
        DbfColumnPtr column(*it);
        values_.push_back(DbfValue::create(column, memo));
    }
}

void DbfRecord::read(std::istream &stream) {
    uint8_t deleted = read_raw<uint8_t>(stream);
    is_deleted_ = (deleted == 0x2A);

    for (auto it = std::begin(values_); it!=std::end(values_); ++it) {
        DbfValuePtr value(*it);
        value->read(stream);
    }
}

bool DbfRecord::is_deleted() const {
    return is_deleted_;
}

DbfValuePtr DbfRecord::value(int index) const {
    return values_[index];
}

DbfValuePtr DbfRecord::value(const std::string &column_name) const {
    return DbfValuePtr();
}

std::vector<DbfValuePtr> DbfRecord::values() const {
    return values_;
}


void DbfRecord::to_csv(std::ostream &os,
                       const bool skip_deleted_records,
                       const std::string &append_csv_data) {
    if (is_deleted() && skip_deleted_records) {
        return;
    }

    for (auto it = std::begin(values_); it != std::end(values_); ++it) {
        DbfValuePtr value(*it);
        value->to_csv(os);

        if (it != (std::end(values_) - 1)) {
            os << ",";
        }
    }

    if (!skip_deleted_records) {
        os << "," << (is_deleted() ? 'T' : 'F');
    }

    if (!append_csv_data.empty()) {
        os << "," << append_csv_data;
    }

    os << std::endl;

}


