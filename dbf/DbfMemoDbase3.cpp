//
// Created by Chris Richards on 05/05/2016.
//

#include <boost/algorithm/string/trim.hpp>
#include <sstream>
#include "DbfMemoDbase3.h"


DbfMemoDbase3::DbfMemoDbase3(const std::string &filename)
    : DbfMemo(filename) {

}

DbfMemoDbase3::~DbfMemoDbase3() {

}

std::string DbfMemoDbase3::build_memo(const int start_block) {
    int pos = offset(start_block);
    file_.seekg(pos);

    std::stringstream memo_text;

    std::string buffer;
    buffer.resize(block_size());

    do {
        file_.read(&buffer[0], block_size());
        boost::trim(buffer);
        memo_text << buffer;
    } while (buffer.size() >= block_size());

    return memo_text.str();
}
