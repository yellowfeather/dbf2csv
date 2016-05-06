//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfTable.h>

class Dbase31ColumnFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_31.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    Dbase31ColumnFixture() : Test() {
    }

    virtual ~Dbase31ColumnFixture() {
    }

    std::vector<DbfColumnPtr> columns() {
        return dbf_table_->columns();
    }

    DbfColumnPtr column(int index) {
        std::vector<DbfColumnPtr> columns = dbf_table_->columns();
        return columns[index];
    }

    DbfTablePtr dbf_table_;
};

TEST_F(Dbase31ColumnFixture, column_count_check) {
    size_t column_count = columns().size();
    EXPECT_EQ(11, column_count);
}

TEST_F(Dbase31ColumnFixture, column1_check) {
    DbfColumnPtr col = column(0);
    EXPECT_EQ(0, col->index());
    EXPECT_EQ("PRODUCTID", col->name());
    EXPECT_EQ(DbfColumn::kSignedLong, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase31ColumnFixture, column2_check) {
    DbfColumnPtr col = column(1);
    EXPECT_EQ(1, col->index());
    EXPECT_EQ("PRODUCTNAM", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(40, col->length());
}

TEST_F(Dbase31ColumnFixture, column3_check) {
    DbfColumnPtr col = column(2);
    EXPECT_EQ(2, col->index());
    EXPECT_EQ("SUPPLIERID", col->name());
    EXPECT_EQ(DbfColumn::kSignedLong, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase31ColumnFixture, column4_check) {
    DbfColumnPtr col = column(3);
    EXPECT_EQ(3, col->index());
    EXPECT_EQ("CATEGORYID", col->name());
    EXPECT_EQ(DbfColumn::kSignedLong, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase31ColumnFixture, column5_check) {
    DbfColumnPtr col = column(4);
    EXPECT_EQ(4, col->index());
    EXPECT_EQ("QUANTITYPE", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase31ColumnFixture, column6_check) {
    DbfColumnPtr col = column(5);
    EXPECT_EQ(5, col->index());
    EXPECT_EQ("UNITPRICE", col->name());
    EXPECT_EQ(DbfColumn::kCurrency, col->type());
    EXPECT_EQ(8, col->length());
}

TEST_F(Dbase31ColumnFixture, column7_check) {
    DbfColumnPtr col = column(6);
    EXPECT_EQ(6, col->index());
    EXPECT_EQ("UNITSINSTO", col->name());
    EXPECT_EQ(DbfColumn::kSignedLong, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase31ColumnFixture, column8_check) {
    DbfColumnPtr col = column(7);
    EXPECT_EQ(7, col->index());
    EXPECT_EQ("UNITSONORD", col->name());
    EXPECT_EQ(DbfColumn::kSignedLong, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase31ColumnFixture, column9_check) {
    DbfColumnPtr col = column(8);
    EXPECT_EQ(8, col->index());
    EXPECT_EQ("REORDERLEV", col->name());
    EXPECT_EQ(DbfColumn::kSignedLong, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase31ColumnFixture, column10_check) {
    DbfColumnPtr col = column(9);
    EXPECT_EQ(9, col->index());
    EXPECT_EQ("DISCONTINU", col->name());
    EXPECT_EQ(DbfColumn::kBoolean, col->type());
    EXPECT_EQ(1, col->length());
}

TEST_F(Dbase31ColumnFixture, column11_check) {
    DbfColumnPtr col = column(10);
    EXPECT_EQ(10, col->index());
    EXPECT_EQ("_NullFlags", col->name());
    EXPECT_EQ('0', col->type());
    EXPECT_EQ(1, col->length());
}

