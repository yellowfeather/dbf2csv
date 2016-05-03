//
// Created by Chris Richards on 27/04/2016.
//

#ifndef DBF2CSV_DBF_COLUMN_H
#define DBF2CSV_DBF_COLUMN_H


#include <string>
#include <memory>
#include <vector>

class DbfColumn {
public:
    typedef enum DbfColumnType: char {
        kNumber      = 'N',
        kSignedLong  = 'I',
        kFloat       = 'F',
        kCurrency    = 'Y',
        kDate        = 'D',
        kDateTime    = 'T',
        kBoolean     = 'L',
        kMemo        = 'M',
        kDouble      = 'B',
        kGeneral     = 'G',
        kCharacter   = 'C'
    } DbfColumnType;

    DbfColumn(std::istream &stream, int index);

    int index() const;
    std::string name() const;
    DbfColumnType type() const;
    int length() const;
    int decimal() const;

private:
    void read(std::istream &stream);

    int index_;
    std::string name_;
    DbfColumnType type_;
    int length_;
    int decimal_;
};

typedef std::shared_ptr<DbfColumn> DbfColumnPtr;

#endif //DBF2CSV_DBF_COLUMN_H
