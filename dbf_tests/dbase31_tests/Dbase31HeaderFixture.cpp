//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfHeader.h>
#include <DbfTable.h>

class Dbase31HeaderFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_31.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    Dbase31HeaderFixture() : Test() {
    }

    virtual ~Dbase31HeaderFixture() {
    }

    DbfHeaderPtr header() {
        return dbf_table_->header();
    }

    DbfTablePtr dbf_table_;
};

TEST_F(Dbase31HeaderFixture, version_check) {
    int version = header()->version();
    EXPECT_EQ(0x31, version);
}

TEST_F(Dbase31HeaderFixture, updated_at_check) {
    std::string updated_at = header()->updated_at();
    EXPECT_EQ("020802", updated_at);
}

TEST_F(Dbase31HeaderFixture, header_length_check) {
    int header_length = header()->header_length();
    EXPECT_EQ(648, header_length);
}

TEST_F(Dbase31HeaderFixture, record_length_check) {
    int record_length = header()->record_length();
    EXPECT_EQ(95, record_length);
}

TEST_F(Dbase31HeaderFixture, record_count_check) {
    int record_count = header()->record_count();
    EXPECT_EQ(77, record_count);
}
