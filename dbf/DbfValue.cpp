//
// Created by Chris Richards on 03/05/2016.
//

#include "DbfValue.h"
#include "TypedDbfValue.h"

DbfValue::DbfValue(DbfColumnPtr column)
    : column_(column) {
    buffer_.resize(column->length());
}

void DbfValue::buffer_read(std::istream &stream) {
    stream.read(&buffer_[0], column_->length());
}

DbfValuePtr DbfValue::create(DbfColumnPtr column) {
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
            break;
        case DbfColumn::kDate: {
            value = DbfValuePtr(new TypedDbfValue<std::string>(column));
            break;
        }
        case DbfColumn::kDateTime:
            break;
        case DbfColumn::kBoolean: {
            value = DbfValuePtr(new TypedDbfValue<bool>(column));
            break;
        }
        case DbfColumn::kMemo: {
            value = DbfValuePtr(new TypedDbfValue<std::string>(column));
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


