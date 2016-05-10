//
// Created by Chris Richards on 27/04/2016.
//

#ifndef DBF2CSV_DBF_TABLE_H
#define DBF2CSV_DBF_TABLE_H

#include <string>
#include <vector>
#include <fstream>
#include "DbfColumn.h"
#include "DbfHeader.h"
#include "DbfMemo.h"
#include "DbfRecord.h"

class DbfTable {
public:
    DbfTable();
    DbfTable(const std::string &filename, bool skip_deleted_records = true);
    virtual ~DbfTable();

    void open(const std::string &filename);
    void close();

    bool good() const;

    bool skip_deleted_records() const;
    void skip_deleted_records(bool skip_deleted_records);

    bool has_memo_file() const;
    std::string memo_filename() const;

    DbfHeaderPtr header() const;
    std::vector<DbfColumnPtr> columns();
    DbfMemoPtr memo() const { return memo_; }

    void get_record(DbfRecordPtr &record);

    void to_csv(std::ostream &os,
                const bool lowercase_header_names,
                const std::string &append_csv_header,
                const std::string &append_csv_data);
private:
    void init();
    void read_columns(std::istream &file);
    DbfMemoPtr create_memo(const std::string &filename) const;

    void seek(const int &offset);
    void seek_to_record(const int &index);

    bool skip_deleted_records_;
    std::string filename_;
    std::ifstream file_;

    DbfHeaderPtr header_;
    std::vector<DbfColumnPtr> columns_;
    DbfMemoPtr memo_;
};

typedef std::shared_ptr<DbfTable> DbfTablePtr;

#endif //DBF2CSV_DBF_TABLE_H
