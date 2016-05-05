//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfTable.h>

class Dbase03TableFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_03.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    Dbase03TableFixture() : Test() {
    }

    virtual ~Dbase03TableFixture() {
    }

    DbfTablePtr dbf_table_;
};

TEST_F(Dbase03TableFixture, good_check) {
    EXPECT_TRUE(dbf_table_->good());
}

TEST_F(Dbase03TableFixture, has_memo_check) {
    EXPECT_FALSE(dbf_table_->has_memo_file());
}
