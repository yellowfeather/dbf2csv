//
// Created by Chris Richards on 05/05/2016.
//

#include "DbfMemoDbase4.h"


DbfMemoDbase4::DbfMemoDbase4(const std::string &filename)
    : DbfMemo(filename) {

}

DbfMemoDbase4::~DbfMemoDbase4() {

}

std::string DbfMemoDbase4::build_memo(const int start_block) {
    int pos = offset(start_block);
    file_.seekg(pos);

    std::string memo_text;
    memo_text.resize(kBlockHeaderSize);

    file_.read(&memo_text[0], kBlockHeaderSize);
//    @data.read(@data.read(BLOCK_HEADER_SIZE).unpack('x4L').first)

    return std::string();
}
