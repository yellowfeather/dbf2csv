//
// Created by Chris Richards on 03/05/2016.
//

#ifndef DBF2CSV_DBFVALUE_H
#define DBF2CSV_DBFVALUE_H


#include <string>
#include <vector>
#include "DbfColumn.h"

class DbfValue;
typedef std::shared_ptr<DbfValue> DbfValuePtr;

class DbfValue {
public:
    static DbfValuePtr create(DbfColumnPtr column);

    virtual void read(std::istream &stream) = 0;

    virtual void to_csv(std::ostream &os) const = 0;

protected:
    DbfValue(DbfColumnPtr column);
    void buffer_read(std::istream &stream);

    DbfColumnPtr column_;
    std::vector<char> buffer_;
};


#endif //DBF2CSV_DBFVALUE_H
