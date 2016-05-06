//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfTable.h>

class DbaseF5TableFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_f5.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    DbaseF5TableFixture() : Test() {
    }

    virtual ~DbaseF5TableFixture() {
    }

    DbfTablePtr dbf_table_;
};

TEST_F(DbaseF5TableFixture, good_check) {
    EXPECT_TRUE(dbf_table_->good());
}

TEST_F(DbaseF5TableFixture, has_memo_check) {
    EXPECT_TRUE(dbf_table_->has_memo_file());
}

TEST_F(DbaseF5TableFixture, memo_filename_check) {
    EXPECT_EQ("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_f5.fpt", dbf_table_->memo_filename());
}
