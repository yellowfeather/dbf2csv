//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfRecord.h>
#include <DbfTable.h>
#include <TypedDbfValue.h>

class DbaseF5RecordFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_f5.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    DbaseF5RecordFixture() : Test() {
    }

    virtual ~DbaseF5RecordFixture() {
    }


    DbfTablePtr dbf_table_;
};

TEST_F(DbaseF5RecordFixture, record_count_check) {
    DbfHeaderPtr header(dbf_table_->header());
    long record_count = header->record_count();
    EXPECT_EQ(975, record_count);
}

TEST_F(DbaseF5RecordFixture, record1_check) {
    DbfRecordPtr record(new DbfRecord(dbf_table_.get(), dbf_table_->memo()));
    dbf_table_->get_record(record);

    std::vector<DbfValuePtr> values(record->values());
    EXPECT_EQ(59, values.size());

    EXPECT_EQ(1, record->value<int>(0).value());
    EXPECT_EQ("h", record->value<std::string>(1).value());
    EXPECT_EQ("joan-ramon", record->value<std::string>(2).value());
    EXPECT_EQ("ivern", record->value<std::string>(3).value());
    EXPECT_EQ("pinazo", record->value<std::string>(4).value());
    EXPECT_EQ("*77665875", record->value<std::string>(5).value());
    EXPECT_EQ("petaquilla", record->value<std::string>(6).value());
    EXPECT_EQ(2, record->value<int>(7).value());
    EXPECT_EQ(3, record->value<int>(8).value());
    EXPECT_FALSE(record->value<std::string>(9));
    EXPECT_EQ("19510113", record->value<std::string>(10).value());
    EXPECT_EQ("el vendrell", record->value<std::string>(11).value());
    EXPECT_EQ("el vendrell", record->value<std::string>(12).value());
    EXPECT_EQ("baix pened\x8As", record->value<std::string>(13).value());
    EXPECT_FALSE(record->value<std::string>(14));
    EXPECT_EQ("catalunya", record->value<std::string>(15).value());
    EXPECT_EQ("qu\xA1mic prof sec", record->value<std::string>(16).value());
    EXPECT_FALSE(record->value<std::string>(17));
    EXPECT_FALSE(record->value<std::string>(18));
//    EXPECT_EQ("050712TR2819.cor", record->value<std::string>(18).value());
//    EXPECT_EQ(2, record->value<int>(19).value());
//    EXPECT_EQ(2, record->value<int>(20).value());
//    EXPECT_EQ("MS4", record->value<std::string>(21).value());
//    EXPECT_EQ(1331, record->value<int>(22).value());
//    EXPECT_EQ(226625.0f, record->value<float>(23).value());
//    EXPECT_EQ(1131.323f, record->value<float>(24).value());
//    EXPECT_EQ(3.1f, record->value<float>(25).value());
//    EXPECT_EQ(1.3f, record->value<float>(26).value());
//    EXPECT_EQ(0.897088f, record->value<float>(27).value());
//    EXPECT_EQ(557904.898f, record->value<float>(28).value());
//    EXPECT_EQ(2212577.192f, record->value<float>(29).value());
//    EXPECT_EQ(401, record->value<int>(30).value());
}
