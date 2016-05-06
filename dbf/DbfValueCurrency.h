//
// Created by Chris Richards on 06/05/2016.
//

#ifndef DBF2CSV_DBFVALUECURRENCY_H
#define DBF2CSV_DBFVALUECURRENCY_H


#include "TypedDbfValue.h"

class DbfValueCurrency : public TypedDbfValue<double> {
public:
    DbfValueCurrency(DbfColumnPtr column);

    void read(std::istream &stream);
};


#endif //DBF2CSV_DBFVALUECURRENCY_H
