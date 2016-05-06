//
// Created by Chris Richards on 05/05/2016.
//

#include <vector>
#include <boost/algorithm/string/trim.hpp>
#include "DbfMemoFoxpro.h"
#include "DbfUtils.h"


DbfMemoFoxpro::DbfMemoFoxpro(const std::string &filename)
    : DbfMemo(filename) {
    block_size_ = calc_block_size();
}

DbfMemoFoxpro::~DbfMemoFoxpro() {

}

std::string DbfMemoFoxpro::build_memo(const long &start_block) {
    int pos = offset(start_block);
    file_.seekg(pos);

    uint32_t block_type = __builtin_bswap32(read_raw<uint32_t>(file_));
    uint32_t memo_length = __builtin_bswap32(read_raw<uint32_t>(file_));

    if ((block_type != 1) || (memo_length == 0)) {
        return std::string();
    }

    std::string memo_text;
    memo_text.resize(memo_length);
    file_.read(&memo_text[0], memo_length);

    boost::trim(memo_text);
    return memo_text;
}

int DbfMemoFoxpro::calc_block_size() {
    file_.seekg(0, std::ios_base::beg);

    // Location of next free block1
    uint32_t next_block = __builtin_bswap32(read_raw<uint32_t>(file_));
    uint16_t unused = __builtin_bswap16(read_raw<uint16_t>(file_));
    uint16_t block_size = __builtin_bswap16(read_raw<uint16_t>(file_));
    return block_size;
}