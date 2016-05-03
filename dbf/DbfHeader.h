//
// Created by Chris Richards on 27/04/2016.
//

#ifndef DBF2CSV_DBF_HEADER_H
#define DBF2CSV_DBF_HEADER_H

#include <memory>
#include <string>

class DbfHeader{
public:
    DbfHeader(std::ifstream &file);

    int version() const;
    std::string version_description() const;
    bool is_foxpro() const;

    std::string updated_at() const;
    int header_length() const;
    int record_length() const;
    long record_count() const;

private:
    void read(std::ifstream &file);

    int version_;
    std::string updated_at_;
    int header_length_;
    int record_length_;
    long record_count_;

};

typedef std::shared_ptr<DbfHeader> DbfHeaderPtr;

#endif //DBF2CSV_DBF_HEADER_H
