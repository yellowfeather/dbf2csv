//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfRecord.h>
#include <DbfTable.h>
#include <TypedDbfValue.h>

class Dbase30RecordFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_30.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    Dbase30RecordFixture() : Test() {
    }

    virtual ~Dbase30RecordFixture() {
    }


    DbfTablePtr dbf_table_;
};

TEST_F(Dbase30RecordFixture, record_count_check) {
    DbfHeaderPtr header(dbf_table_->header());
    long record_count = header->record_count();
    EXPECT_EQ(34, record_count);
}

TEST_F(Dbase30RecordFixture, record1_check) {
    DbfRecordPtr record(new DbfRecord(dbf_table_.get(), dbf_table_->memo()));
    dbf_table_->get_record(record);

    std::vector<DbfValuePtr> values(record->values());
    EXPECT_EQ(145, values.size());

    EXPECT_EQ("1999.1", record->value<std::string>(0).value());
    EXPECT_FALSE(record->value<float>(1));
    EXPECT_FALSE(record->value<std::string>(2));
    EXPECT_FALSE(record->value<std::string>(3));
    EXPECT_EQ("File Cabinet 2", record->value<std::string>(4).value());
    EXPECT_EQ("Ear & Ernie Wedding 1942", record->value<std::string>(5).value());
    EXPECT_EQ("P", record->value<std::string>(6).value());
    EXPECT_EQ("Parr, Mary L.", record->value<std::string>(7).value());
    EXPECT_EQ("19990305", record->value<std::string>(8).value());
    EXPECT_FALSE(record->value<std::string>(9));
    EXPECT_EQ("Domestic Life\r\nWeddings", record->value<std::string>(10).value());
    EXPECT_EQ("Rocky Pine Ranch Collection", record->value<std::string>(11).value());
    EXPECT_EQ("20000614", record->value<std::string>(12).value());
    EXPECT_EQ("Parr, Mary L.", record->value<std::string>(13).value());
    EXPECT_EQ("Good", record->value<std::string>(14).value());
    EXPECT_EQ("03/05/1999 - Photograph has been cut down from a larger size.  MLP", record->value<std::string>(15).value());
    EXPECT_EQ("Folder P-R", record->value<std::string>(16).value());
    EXPECT_EQ("All rights belong to the PastPerfect Museum.", record->value<std::string>(17).value());
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
