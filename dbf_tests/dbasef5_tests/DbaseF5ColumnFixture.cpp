//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfTable.h>

class DbaseF5ColumnFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_f5.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    DbaseF5ColumnFixture() : Test() {
    }

    virtual ~DbaseF5ColumnFixture() {
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

TEST_F(DbaseF5ColumnFixture, column_count_check) {
    size_t column_count = columns().size();
    EXPECT_EQ(59, column_count);
}

TEST_F(DbaseF5ColumnFixture, column1_check) {
    DbfColumnPtr col = column(0);
    EXPECT_EQ(0, col->index());
    EXPECT_EQ("NF", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(5, col->length());
}

TEST_F(DbaseF5ColumnFixture, column2_check) {
    DbfColumnPtr col = column(1);
    EXPECT_EQ(1, col->index());
    EXPECT_EQ("SEXE", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(1, col->length());
}

TEST_F(DbaseF5ColumnFixture, column3_check) {
    DbfColumnPtr col = column(2);
    EXPECT_EQ(2, col->index());
    EXPECT_EQ("NOM", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(DbaseF5ColumnFixture, column4_check) {
    DbfColumnPtr col = column(3);
    EXPECT_EQ(3, col->index());
    EXPECT_EQ("COG1", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column5_check) {
    DbfColumnPtr col = column(4);
    EXPECT_EQ(4, col->index());
    EXPECT_EQ("COG2", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column6_check) {
    DbfColumnPtr col = column(5);
    EXPECT_EQ(5, col->index());
    EXPECT_EQ("TELEFON", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(9, col->length());
}

TEST_F(DbaseF5ColumnFixture, column7_check) {
    DbfColumnPtr col = column(6);
    EXPECT_EQ(6, col->index());
    EXPECT_EQ("RENOM", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column8_check) {
    DbfColumnPtr col = column(7);
    EXPECT_EQ(7, col->index());
    EXPECT_EQ("NFP", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(5, col->length());
}

TEST_F(DbaseF5ColumnFixture, column9_check) {
    DbfColumnPtr col = column(8);
    EXPECT_EQ(8, col->index());
    EXPECT_EQ("NFM", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(5, col->length());
}

TEST_F(DbaseF5ColumnFixture, column10_check) {
    DbfColumnPtr col = column(9);
    EXPECT_EQ(9, col->index());
    EXPECT_EQ("ARXN", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(10, col->length());
}

TEST_F(DbaseF5ColumnFixture, column11_check) {
    DbfColumnPtr col = column(10);
    EXPECT_EQ(10, col->index());
    EXPECT_EQ("DATN", col->name());
    EXPECT_EQ(DbfColumn::kDate, col->type());
    EXPECT_EQ(8, col->length());
}

TEST_F(DbaseF5ColumnFixture, column12_check) {
    DbfColumnPtr col = column(11);
    EXPECT_EQ(11, col->index());
    EXPECT_EQ("LLON", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column13_check) {
    DbfColumnPtr col = column(12);
    EXPECT_EQ(12, col->index());
    EXPECT_EQ("MUNN", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column14_check) {
    DbfColumnPtr col = column(13);
    EXPECT_EQ(13, col->index());
    EXPECT_EQ("COMN", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column15_check) {
    DbfColumnPtr col = column(14);
    EXPECT_EQ(14, col->index());
    EXPECT_EQ("PROV", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column16_check) {
    DbfColumnPtr col = column(15);
    EXPECT_EQ(15, col->index());
    EXPECT_EQ("PAIN", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column17_check) {
    DbfColumnPtr col = column(16);
    EXPECT_EQ(16, col->index());
    EXPECT_EQ("OFIC", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column18_check) {
    DbfColumnPtr col = column(17);
    EXPECT_EQ(17, col->index());
    EXPECT_EQ("ARXB", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(10, col->length());
}

TEST_F(DbaseF5ColumnFixture, column19_check) {
    DbfColumnPtr col = column(18);
    EXPECT_EQ(18, col->index());
    EXPECT_EQ("DATB", col->name());
    EXPECT_EQ(DbfColumn::kDate, col->type());
    EXPECT_EQ(8, col->length());
}

TEST_F(DbaseF5ColumnFixture, column20_check) {
    DbfColumnPtr col = column(19);
    EXPECT_EQ(19, col->index());
    EXPECT_EQ("LLOB", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column21_check) {
    DbfColumnPtr col = column(20);
    EXPECT_EQ(20, col->index());
    EXPECT_EQ("MUNB", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column22_check) {
    DbfColumnPtr col = column(21);
    EXPECT_EQ(21, col->index());
    EXPECT_EQ("COMB", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column23_check) {
    DbfColumnPtr col = column(22);
    EXPECT_EQ(22, col->index());
    EXPECT_EQ("PAIB", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column24_check) {
    DbfColumnPtr col = column(23);
    EXPECT_EQ(23, col->index());
    EXPECT_EQ("DRIB", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(30, col->length());
}

TEST_F(DbaseF5ColumnFixture, column25_check) {
    DbfColumnPtr col = column(24);
    EXPECT_EQ(24, col->index());
    EXPECT_EQ("INAB", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(30, col->length());
}

TEST_F(DbaseF5ColumnFixture, column26_check) {
    DbfColumnPtr col = column(25);
    EXPECT_EQ(25, col->index());
    EXPECT_EQ("OFTB", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(10, col->length());
}

TEST_F(DbaseF5ColumnFixture, column27_check) {
    DbfColumnPtr col = column(26);
    EXPECT_EQ(26, col->index());
    EXPECT_EQ("OFNB", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(DbaseF5ColumnFixture, column28_check) {
    DbfColumnPtr col = column(27);
    EXPECT_EQ(27, col->index());
    EXPECT_EQ("AXC1", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(10, col->length());
}

TEST_F(DbaseF5ColumnFixture, column29_check) {
    DbfColumnPtr col = column(28);
    EXPECT_EQ(28, col->index());
    EXPECT_EQ("DTC1", col->name());
    EXPECT_EQ(DbfColumn::kDate, col->type());
    EXPECT_EQ(8, col->length());
}

TEST_F(DbaseF5ColumnFixture, column30_check) {
    DbfColumnPtr col = column(29);
    EXPECT_EQ(29, col->index());
    EXPECT_EQ("LLC1", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(DbaseF5ColumnFixture, column31_check) {
    DbfColumnPtr col = column(30);
    EXPECT_EQ(30, col->index());
    EXPECT_EQ("NFC1", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(5, col->length());
}










