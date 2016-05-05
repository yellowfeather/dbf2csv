//
// Created by Chris Richards on 05/05/2016.
//

#ifndef DBF2CSV_DBFMEMOFOXPRO_H
#define DBF2CSV_DBFMEMOFOXPRO_H

#include "DbfMemo.h"

class DbfMemoFoxpro : public DbfMemo {
public:
    DbfMemoFoxpro(const std::string &filename);
    virtual ~DbfMemoFoxpro();

    std::string build_memo(const int start_block);

private:
    int calc_block_size();

    static const int kFptHeaderSize = 512;
};


#endif //DBF2CSV_DBFMEMOFOXPRO_H
