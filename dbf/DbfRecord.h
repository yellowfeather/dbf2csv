//
// Created by Chris Richards on 27/04/2016.
//

#ifndef DBF2CSV_DBF_RECORD_H
#define DBF2CSV_DBF_RECORD_H

#include <memory>
#include <vector>
#include <boost/any.hpp>
#include "DbfColumn.h"
#include "DbfValue.h"

class DbfTable;

class DbfRecord {
public:
    DbfRecord(DbfTable *dbf_table);

    void read(std::istream &stream);

    // TODO: operator [int] access (DbfColumn index)
    // TODO: operator [string] access (DbfColumn name)
    // TODO: typed access e.g. T value<T>(int index);

    bool is_deleted() const;

    DbfValuePtr value(int index) const;
    DbfValuePtr value(const std::string& column_name) const;
    std::vector<DbfValuePtr> values() const;

    void to_csv(std::ostream &os);

private:
    bool is_deleted_;
    int record_length_;
    std::vector<DbfColumnPtr> columns_;
    int version_;
    std::vector<DbfValuePtr> values_;
};

typedef std::shared_ptr<DbfRecord> DbfRecordPtr;

#endif //DBF2CSV_DBF_RECORD_H
