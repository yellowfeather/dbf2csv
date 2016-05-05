//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfTable.h>

class Dbase30TableFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_30.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    Dbase30TableFixture() : Test() {
    }

    virtual ~Dbase30TableFixture() {
    }

    DbfTablePtr dbf_table_;
};

TEST_F(Dbase30TableFixture, good_check) {
    EXPECT_TRUE(dbf_table_->good());
}

TEST_F(Dbase30TableFixture, has_memo_check) {
    EXPECT_TRUE(dbf_table_->has_memo_file());
}

TEST_F(Dbase30TableFixture, memo_filename_check) {
    EXPECT_EQ("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_30.fpt", dbf_table_->memo_filename());
}
