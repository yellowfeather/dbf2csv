//
// Created by Chris Richards on 06/05/2016.
//

#include "DbfValueCurrency.h"
#include "DbfUtils.h"

DbfValueCurrency::DbfValueCurrency(DbfColumnPtr column)
    : TypedDbfValue<double>(column) {

}

void DbfValueCurrency::read(std::istream &stream) {
    if (stream.peek() == '\0') {
        buffer_read(stream);
        value_ = boost::none;
    }
    else {
        uint64_t raw_value = read_raw<uint64_t>(stream);
        value_ = raw_value / 10000.0f;
    }
}

