//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfTable.h>

class DbfTableFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_03.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    DbfTableFixture() : Test() {
    }

    virtual ~DbfTableFixture() {
    }

    DbfTablePtr dbf_table_;
};

TEST_F(DbfTableFixture, good_check) {
    EXPECT_TRUE(dbf_table_->good());
}

