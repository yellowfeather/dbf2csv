//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfHeader.h>
#include <DbfTable.h>

class DbaseF5HeaderFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_f5.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    DbaseF5HeaderFixture() : Test() {
    }

    virtual ~DbaseF5HeaderFixture() {
    }

    DbfHeaderPtr header() {
        return dbf_table_->header();
    }

    DbfTablePtr dbf_table_;
};

TEST_F(DbaseF5HeaderFixture, version_check) {
    int version = header()->version();
    EXPECT_EQ(0xF5, version);
}

TEST_F(DbaseF5HeaderFixture, updated_at_check) {
    std::string updated_at = header()->updated_at();
    EXPECT_EQ("280204", updated_at);
}

TEST_F(DbaseF5HeaderFixture, header_length_check) {
    int header_length = header()->header_length();
    EXPECT_EQ(1921, header_length);
}

TEST_F(DbaseF5HeaderFixture, record_length_check) {
    int record_length = header()->record_length();
    EXPECT_EQ(969, record_length);
}

TEST_F(DbaseF5HeaderFixture, record_count_check) {
    int record_count = header()->record_count();
    EXPECT_EQ(975, record_count);
}
