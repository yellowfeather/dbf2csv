//
// Created by Chris Richards on 04/05/2016.
//

#include "DbfMemo.h"

DbfMemo::DbfMemo() {

}

DbfMemo::DbfMemo(const std::string &filename)
    : block_size_(kBlockSize) {
    open(filename);
}

DbfMemo::~DbfMemo() {
    if (file_.is_open()) {
        file_.close();
    }
}

void DbfMemo::open(const std::string &filename) {
    file_.open(filename, std::ios::binary | std::ios::in);
}

void DbfMemo::close() {
    file_.close();
}

bool DbfMemo::good() const {
    return file_.good();
}

boost::optional<std::string> DbfMemo::get(const int start_block) {
    if (start_block <= 0) {
        return boost::optional<std::string>();
    }

    std::string s(build_memo(start_block));
    return boost::optional<std::string>(s);
}

int DbfMemo::offset(const int start_block) {
    return start_block * block_size();
}

int DbfMemo::content_size(const int memo_size) {
    return (memo_size - block_size()) + kBlockHeaderSize;
}

int DbfMemo::block_content_size() {
    return block_size() - kBlockHeaderSize;
}

