//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfHeader.h>
#include <DbfTable.h>

class DbfHeaderFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_03.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    DbfHeaderFixture() : Test() {
    }

    virtual ~DbfHeaderFixture() {
    }

    DbfHeaderPtr header() {
        return dbf_table_->header();
    }

    DbfTablePtr dbf_table_;
};

TEST_F(DbfHeaderFixture, version_check) {
    int version = header()->version();
    EXPECT_EQ(0x03, version);
}

TEST_F(DbfHeaderFixture, updated_at_check) {
    std::string updated_at = header()->updated_at();
    EXPECT_EQ("130705", updated_at);
}

TEST_F(DbfHeaderFixture, header_length_check) {
    int header_length = header()->header_length();
    EXPECT_EQ(1025, header_length);
}

TEST_F(DbfHeaderFixture, record_length_check) {
    int record_length = header()->record_length();
    EXPECT_EQ(590, record_length);
}

TEST_F(DbfHeaderFixture, record_count_check) {
    int record_count = header()->record_count();
    EXPECT_EQ(14, record_count);
}
