//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfTable.h>

class Dbase30ColumnFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_30.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    Dbase30ColumnFixture() : Test() {
    }

    virtual ~Dbase30ColumnFixture() {
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

TEST_F(Dbase30ColumnFixture, column_count_check) {
    size_t column_count = columns().size();
    EXPECT_EQ(145, column_count);
}

TEST_F(Dbase30ColumnFixture, column1_check) {
    DbfColumnPtr col = column(0);
    EXPECT_EQ(0, col->index());
    EXPECT_EQ("ACCESSNO", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(Dbase30ColumnFixture, column2_check) {
    DbfColumnPtr col = column(1);
    EXPECT_EQ(1, col->index());
    EXPECT_EQ("ACQVALUE", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(12, col->length());
    EXPECT_EQ(2, col->decimal());
}

TEST_F(Dbase30ColumnFixture, column3_check) {
    DbfColumnPtr col = column(2);
    EXPECT_EQ(2, col->index());
    EXPECT_EQ("APPNOTES", col->name());
    EXPECT_EQ(DbfColumn::kMemo, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase30ColumnFixture, column4_check) {
    DbfColumnPtr col = column(3);
    EXPECT_EQ(3, col->index());
    EXPECT_EQ("APPRAISOR", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(75, col->length());
}

TEST_F(Dbase30ColumnFixture, column5_check) {
    DbfColumnPtr col = column(4);
    EXPECT_EQ(4, col->index());
    EXPECT_EQ("CABINET", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(25, col->length());
}

TEST_F(Dbase30ColumnFixture, column6_check) {
    DbfColumnPtr col = column(5);
    EXPECT_EQ(5, col->index());
    EXPECT_EQ("CAPTION", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(30, col->length());
}

TEST_F(Dbase30ColumnFixture, column7_check) {
    DbfColumnPtr col = column(6);
    EXPECT_EQ(6, col->index());
    EXPECT_EQ("CAT", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(1, col->length());
}

TEST_F(Dbase30ColumnFixture, column8_check) {
    DbfColumnPtr col = column(7);
    EXPECT_EQ(7, col->index());
    EXPECT_EQ("CATBY", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(25, col->length());
}

TEST_F(Dbase30ColumnFixture, column9_check) {
    DbfColumnPtr col = column(8);
    EXPECT_EQ(8, col->index());
    EXPECT_EQ("CATDATE", col->name());
    EXPECT_EQ(DbfColumn::kDate, col->type());
    EXPECT_EQ(8, col->length());
}

TEST_F(Dbase30ColumnFixture, column10_check) {
    DbfColumnPtr col = column(9);
    EXPECT_EQ(9, col->index());
    EXPECT_EQ("CATTYPE", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(Dbase30ColumnFixture, column11_check) {
    DbfColumnPtr col = column(10);
    EXPECT_EQ(10, col->index());
    EXPECT_EQ("CLASSES", col->name());
    EXPECT_EQ(DbfColumn::kMemo, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase30ColumnFixture, column12_check) {
    DbfColumnPtr col = column(11);
    EXPECT_EQ(11, col->index());
    EXPECT_EQ("COLLECTION", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(75, col->length());
}

TEST_F(Dbase30ColumnFixture, column13_check) {
    DbfColumnPtr col = column(12);
    EXPECT_EQ(12, col->index());
    EXPECT_EQ("CONDDATE", col->name());
    EXPECT_EQ(DbfColumn::kDate, col->type());
    EXPECT_EQ(8, col->length());
}

TEST_F(Dbase30ColumnFixture, column14_check) {
    DbfColumnPtr col = column(13);
    EXPECT_EQ(13, col->index());
    EXPECT_EQ("CONDEXAM", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(25, col->length());
}

TEST_F(Dbase30ColumnFixture, column15_check) {
    DbfColumnPtr col = column(14);
    EXPECT_EQ(14, col->index());
    EXPECT_EQ("CONDITION", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(35, col->length());
}

TEST_F(Dbase30ColumnFixture, column16_check) {
    DbfColumnPtr col = column(15);
    EXPECT_EQ(15, col->index());
    EXPECT_EQ("CONDNOTES", col->name());
    EXPECT_EQ(DbfColumn::kMemo, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase30ColumnFixture, column17_check) {
    DbfColumnPtr col = column(16);
    EXPECT_EQ(16, col->index());
    EXPECT_EQ("CONTAINER", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(40, col->length());
}

TEST_F(Dbase30ColumnFixture, column18_check) {
    DbfColumnPtr col = column(17);
    EXPECT_EQ(17, col->index());
    EXPECT_EQ("COPYRIGHT", col->name());
    EXPECT_EQ(DbfColumn::kMemo, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase30ColumnFixture, column19_check) {
    DbfColumnPtr col = column(18);
    EXPECT_EQ(18, col->index());
    EXPECT_EQ("CREATOR", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(80, col->length());
}

TEST_F(Dbase30ColumnFixture, column20_check) {
    DbfColumnPtr col = column(19);
    EXPECT_EQ(19, col->index());
    EXPECT_EQ("CREDIT", col->name());
    EXPECT_EQ(DbfColumn::kMemo, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase30ColumnFixture, column21_check) {
    DbfColumnPtr col = column(20);
    EXPECT_EQ(20, col->index());
    EXPECT_EQ("CURVALMAX", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(12, col->length());
    EXPECT_EQ(2, col->decimal());
}

TEST_F(Dbase30ColumnFixture, column22_check) {
    DbfColumnPtr col = column(21);
    EXPECT_EQ(21, col->index());
    EXPECT_EQ("CURVALUE", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(12, col->length());
    EXPECT_EQ(2, col->decimal());
}

TEST_F(Dbase30ColumnFixture, column23_check) {
    DbfColumnPtr col = column(22);
    EXPECT_EQ(22, col->index());
    EXPECT_EQ("DATASET", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(15, col->length());
}

TEST_F(Dbase30ColumnFixture, column24_check) {
    DbfColumnPtr col = column(23);
    EXPECT_EQ(23, col->index());
    EXPECT_EQ("DATE", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(50, col->length());
}

TEST_F(Dbase30ColumnFixture, column25_check) {
    DbfColumnPtr col = column(24);
    EXPECT_EQ(24, col->index());
    EXPECT_EQ("DESCRIP", col->name());
    EXPECT_EQ(DbfColumn::kMemo, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase30ColumnFixture, column26_check) {
    DbfColumnPtr col = column(25);
    EXPECT_EQ(25, col->index());
    EXPECT_EQ("DIMNOTES", col->name());
    EXPECT_EQ(DbfColumn::kMemo, col->type());
    EXPECT_EQ(4, col->length());
}

TEST_F(Dbase30ColumnFixture, column27_check) {
    DbfColumnPtr col = column(26);
    EXPECT_EQ(26, col->index());
    EXPECT_EQ("DISPVALUE", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(10, col->length());
}

TEST_F(Dbase30ColumnFixture, column28_check) {
    DbfColumnPtr col = column(27);
    EXPECT_EQ(27, col->index());
    EXPECT_EQ("DRAWER", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase30ColumnFixture, column29_check) {
    DbfColumnPtr col = column(28);
    EXPECT_EQ(28, col->index());
    EXPECT_EQ("EARLYDATE", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(4, col->length());
    EXPECT_EQ(0, col->decimal());
}

TEST_F(Dbase30ColumnFixture, column30_check) {
    DbfColumnPtr col = column(29);
    EXPECT_EQ(29, col->index());
    EXPECT_EQ("EVENT", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(80, col->length());
}

TEST_F(Dbase30ColumnFixture, column31_check) {
    DbfColumnPtr col = column(30);
    EXPECT_EQ(30, col->index());
    EXPECT_EQ("EXHIBITID", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(36, col->length());
}










