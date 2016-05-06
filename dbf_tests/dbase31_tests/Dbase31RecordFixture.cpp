//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfRecord.h>
#include <DbfTable.h>
#include <TypedDbfValue.h>

class Dbase31RecordFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_31.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    Dbase31RecordFixture() : Test() {
    }

    virtual ~Dbase31RecordFixture() {
    }


    DbfTablePtr dbf_table_;
};

TEST_F(Dbase31RecordFixture, record_count_check) {
    DbfHeaderPtr header(dbf_table_->header());
    long record_count = header->record_count();
    EXPECT_EQ(77, record_count);
}

TEST_F(Dbase31RecordFixture, record1_check) {
    DbfRecordPtr record(new DbfRecord(dbf_table_.get(), dbf_table_->memo()));
    dbf_table_->get_record(record);

    std::vector<DbfValuePtr> values(record->values());
    EXPECT_EQ(11, values.size());

    EXPECT_EQ(1, record->value<long>(0).value());
    EXPECT_EQ("Chai", record->value<std::string>(1).value());
    EXPECT_EQ(1, record->value<long>(2).value());
    EXPECT_EQ(1, record->value<long>(3).value());
    EXPECT_EQ("10 boxes x 20 bags", record->value<std::string>(4).value());
    EXPECT_EQ(18.0f, record->value<float>(5).value());
    EXPECT_EQ(39, record->value<long>(6).value());
    EXPECT_FALSE(record->value<long>(7));
    EXPECT_EQ(10, record->value<long>(8).value());
    EXPECT_EQ(false, record->value<bool>(9).value());
    EXPECT_FALSE(record->value<std::string>(10));
}
