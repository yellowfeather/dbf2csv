//
// Created by Chris Richards on 27/04/2016.
//

#ifndef DBF2CSV_DBF_RECORD_H
#define DBF2CSV_DBF_RECORD_H

#include <memory>
#include <vector>
#include "DbfColumn.h"
#include "DbfMemo.h"
#include "DbfValue.h"
#include "TypedDbfValue.h"

class DbfTable;

class DbfRecord {
public:
    DbfRecord(DbfTable *dbf_table, DbfMemoPtr memo = nullptr);

    void read(std::istream &stream);

    // TODO: operator [int] access (DbfColumn index)
    // TODO: operator [string] access (DbfColumn name)

    bool is_deleted() const;

    DbfValuePtr value(int index) const;

    template<class T>
    boost::optional<T> value(int index) const {
        DbfValuePtr value = values_[index];
        TypedDbfValue<T> *typed_value = dynamic_cast<TypedDbfValue<T> *>(value.get());
        return typed_value->value();
    }

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
