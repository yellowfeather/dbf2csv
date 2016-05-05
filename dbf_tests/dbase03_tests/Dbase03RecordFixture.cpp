//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfRecord.h>
#include <DbfTable.h>
#include <TypedDbfValue.h>

class Dbase03RecordFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_03.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    Dbase03RecordFixture() : Test() {
    }

    virtual ~Dbase03RecordFixture() {
    }


    DbfTablePtr dbf_table_;
};

TEST_F(Dbase03RecordFixture, record_count_check) {
    DbfHeaderPtr header(dbf_table_->header());
    long record_count = header->record_count();
    EXPECT_EQ(14, record_count);
}

TEST_F(Dbase03RecordFixture, record1_check) {
    DbfRecordPtr record(new DbfRecord(dbf_table_.get()));
    dbf_table_->get_record(record);

    std::vector<DbfValuePtr> values(record->values());
    EXPECT_EQ(31, values.size());

    EXPECT_EQ("0507121", record->value<std::string>(0).value());
    EXPECT_EQ("CMP", record->value<std::string>(1).value());
    EXPECT_EQ("circular", record->value<std::string>(2).value());
    EXPECT_EQ("12", record->value<std::string>(3).value());
    EXPECT_FALSE(record->value<std::string>(4));
    EXPECT_EQ("no", record->value<std::string>(5).value());
    EXPECT_EQ("Good", record->value<std::string>(6).value());
    EXPECT_FALSE(record->value<std::string>(7));
    EXPECT_EQ("20050712", record->value<std::string>(8).value());
    EXPECT_EQ("10:56:30am", record->value<std::string>(9).value());
    EXPECT_EQ(5.2f, record->value<float>(10).value());
    EXPECT_EQ(2.0f, record->value<float>(11).value());
    EXPECT_EQ("Postprocessed Code", record->value<std::string>(12).value());
    EXPECT_EQ("GeoXT", record->value<std::string>(13).value());
    EXPECT_EQ("20050712", record->value<std::string>(14).value());
    EXPECT_EQ("10:56:52am", record->value<std::string>(15).value());
    EXPECT_EQ("New", record->value<std::string>(16).value());
    EXPECT_EQ("Driveway", record->value<std::string>(17).value());
    EXPECT_EQ("050712TR2819.cor", record->value<std::string>(18).value());
    EXPECT_EQ(2, record->value<int>(19).value());
    EXPECT_EQ(2, record->value<int>(20).value());
    EXPECT_EQ("MS4", record->value<std::string>(21).value());
    EXPECT_EQ(1331, record->value<int>(22).value());
    EXPECT_EQ(226625.0f, record->value<float>(23).value());
    EXPECT_EQ(1131.323f, record->value<float>(24).value());
    EXPECT_EQ(3.1f, record->value<float>(25).value());
    EXPECT_EQ(1.3f, record->value<float>(26).value());
    EXPECT_EQ(0.897088f, record->value<float>(27).value());
    EXPECT_EQ(557904.898f, record->value<float>(28).value());
    EXPECT_EQ(2212577.192f, record->value<float>(29).value());
    EXPECT_EQ(401, record->value<int>(30).value());
}
