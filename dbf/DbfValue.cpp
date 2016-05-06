//
// Created by Chris Richards on 03/05/2016.
//

#include <boost/algorithm/string.hpp>

#include "DbfValue.h"
#include "TypedDbfValue.h"
#include "DbfValueCurrency.h"

DbfValue::DbfValue(DbfColumnPtr column, DbfMemoPtr memo)
    : column_(column), memo_(memo) {
    buffer_.resize(column->length());
}

void DbfValue::buffer_read(std::istream &stream) {
    stream.read(&buffer_[0], column_->length());
}

DbfValuePtr DbfValue::create(DbfColumnPtr column, DbfMemoPtr memo) {
    DbfValuePtr value;

    switch (column->type()) {
        case DbfColumn::kNumber:
            if (column->decimal() == 0) {
                value = DbfValuePtr(new TypedDbfValue<int>(column));
            }
            else {
                value = DbfValuePtr(new TypedDbfValue<float>(column));
            }
            break;
        case DbfColumn::kSignedLong:
            value = DbfValuePtr(new TypedDbfValue<long>(column));
            break;
        case DbfColumn::kFloat:
            value = DbfValuePtr(new TypedDbfValue<float>(column));
            break;
        case DbfColumn::kCurrency:
            value = DbfValuePtr(new DbfValueCurrency(column));
            break;
        case DbfColumn::kDate: {
            value = DbfValuePtr(new TypedDbfValue<std::string>(column));
            break;
        }
        case DbfColumn::kDateTime:
            value = DbfValuePtr(new TypedDbfValue<std::string>(column));
            break;
        case DbfColumn::kBoolean: {
            value = DbfValuePtr(new TypedDbfValue<bool>(column));
            break;
        }
        case DbfColumn::kMemo: {
            value = DbfValuePtr(new TypedDbfValue<std::string>(column, memo));
            break;
        }
        case DbfColumn::kDouble:
            value = DbfValuePtr(new TypedDbfValue<float>(column));
            break;
        case DbfColumn::kGeneral:
        case DbfColumn::kCharacter:
        default: {
            value = DbfValuePtr(new TypedDbfValue<std::string>(column));
            break;
        }
    }

    return value;
}

std::string DbfValue::buffer_as_string() const {
    if (buffer_[0] ==  '\0') {
        return std::string();
    }

    std::string s(&buffer_[0], buffer_.size());
    boost::trim(s);
    return s;
}


