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
    DbfHeaderPtr header() const;
    std::vector<DbfColumnPtr> columns();

    void get_record(DbfRecordPtr &record);

    void to_csv(std::ostream &os);
private:
    void init();
    void read_columns(std::istream &file);

    bool skip_deleted_records_;
    std::ifstream file_;

    DbfHeaderPtr header_;
    std::vector<DbfColumnPtr> columns_;
};

typedef std::shared_ptr<DbfTable> DbfTablePtr;

#endif //DBF2CSV_DBF_TABLE_H
