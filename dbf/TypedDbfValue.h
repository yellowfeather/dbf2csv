//
// Created by Chris Richards on 03/05/2016.
//

#ifndef DBF2CSV_TYPEDDBFVALUE_H
#define DBF2CSV_TYPEDDBFVALUE_H

#include <cstdlib>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

#include "DbfColumn.h"
#include "DbfValue.h"

template <class T>
class TypedDbfValue : public DbfValue {
public:
    TypedDbfValue(DbfColumnPtr column, DbfMemoPtr memo = nullptr)
            : DbfValue(column, memo) {
    }

    void read(std::istream &stream);

    void to_csv(std::ostream &os) const {
        if (value_ != boost::none) {
            os << *value_;
        }
    }

    boost::optional<T> value() const {
        return value_;
    }

private:
    boost::optional<T> value_;
};

#endif //DBF2CSV_TYPEDDBFVALUE_H
