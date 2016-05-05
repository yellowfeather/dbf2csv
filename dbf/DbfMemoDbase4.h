//
// Created by Chris Richards on 05/05/2016.
//

#ifndef DBF2CSV_DBFMEMODBASE4_H
#define DBF2CSV_DBFMEMODBASE4_H


#include "DbfMemo.h"

class DbfMemoDbase4 : public DbfMemo {
public:
    DbfMemoDbase4(const std::string &filename);
    virtual ~DbfMemoDbase4();

    std::string build_memo(const int start_block);
};


#endif //DBF2CSV_DBFMEMODBASE4_H
