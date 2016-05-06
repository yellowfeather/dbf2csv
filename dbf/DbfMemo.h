//
// Created by Chris Richards on 04/05/2016.
//

#ifndef DBF2CSV_DBFMEMO_H
#define DBF2CSV_DBFMEMO_H


#include <memory>
#include <fstream>
#include <boost/optional.hpp>

class DbfMemo {
public:
    DbfMemo();
    DbfMemo(const std::string &filename);
    virtual ~DbfMemo();

    void open(const std::string &filename);
    void close();

    bool good() const;

    boost::optional<std::string> get(const long &start_block);

protected:
    static const int kBlockHeaderSize = 8;
    static const int kBlockSize = 512;

    virtual std::string build_memo(const long &start_block) = 0;

    int offset(const long &start_block);
    int content_size(const int &memo_size);
    int block_size() const { return block_size_; }
    int block_content_size();

    std::ifstream file_;
    int block_size_;
};

typedef std::shared_ptr<DbfMemo> DbfMemoPtr;

#endif //DBF2CSV_DBFMEMO_H
