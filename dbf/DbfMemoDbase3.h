//
// Created by Chris Richards on 05/05/2016.
//

#ifndef DBF2CSV_DBFMEMODBASE3_H
#define DBF2CSV_DBFMEMODBASE3_H


#include "DbfMemo.h"

class DbfMemoDbase3 : public DbfMemo {
public:
    DbfMemoDbase3(const std::string &filename);
    virtual ~DbfMemoDbase3();

    std::string build_memo(const int start_block);
};


#endif //DBF2CSV_DBFMEMODBASE3_H
