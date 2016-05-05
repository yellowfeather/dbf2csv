//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfTable.h>

class Dbase03ColumnFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_03.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    Dbase03ColumnFixture() : Test() {
    }

    virtual ~Dbase03ColumnFixture() {
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

TEST_F(Dbase03ColumnFixture, column_count_check) {
    size_t column_count = columns().size();
    EXPECT_EQ(31, column_count);
}

TEST_F(Dbase03ColumnFixture, column1_check) {
    DbfColumnPtr col = column(0);
    EXPECT_EQ(0, col->index());
    EXPECT_EQ("Point_ID", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(12, col->length());
}

TEST_F(Dbase03ColumnFixture, column2_check) {
    DbfColumnPtr col = column(1);
    EXPECT_EQ(1, col->index());
    EXPECT_EQ("Type", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase03ColumnFixture, column3_check) {
    DbfColumnPtr col = column(2);
    EXPECT_EQ(2, col->index());
    EXPECT_EQ("Shape", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase03ColumnFixture, column4_check) {
    DbfColumnPtr col = column(3);
    EXPECT_EQ(3, col->index());
    EXPECT_EQ("Circular_D", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase03ColumnFixture, column5_check) {
    DbfColumnPtr col = column(4);
    EXPECT_EQ(4, col->index());
    EXPECT_EQ("Non_circul", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(60, col->length());
}

TEST_F(Dbase03ColumnFixture, column6_check) {
    DbfColumnPtr col = column(5);
    EXPECT_EQ(5, col->index());
    EXPECT_EQ("Flow_prese", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase03ColumnFixture, column7_check) {
    DbfColumnPtr col = column(6);
    EXPECT_EQ(6, col->index());
    EXPECT_EQ("Condition", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase03ColumnFixture, column8_check) {
    DbfColumnPtr col = column(7);
    EXPECT_EQ(7, col->index());
    EXPECT_EQ("Comments", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(60, col->length());
}

TEST_F(Dbase03ColumnFixture, column9_check) {
    DbfColumnPtr col = column(8);
    EXPECT_EQ(8, col->index());
    EXPECT_EQ("Date_Visit", col->name());
    EXPECT_EQ(DbfColumn::kDate, col->type());
    EXPECT_EQ(8, col->length());
}

TEST_F(Dbase03ColumnFixture, column10_check) {
    DbfColumnPtr col = column(9);
    EXPECT_EQ(9, col->index());
    EXPECT_EQ("Time", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(10, col->length());
}

TEST_F(Dbase03ColumnFixture, column11_check) {
    DbfColumnPtr col = column(10);
    EXPECT_EQ(10, col->index());
    EXPECT_EQ("Max_PDOP", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(5, col->length());
    EXPECT_EQ(1, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column12_check) {
    DbfColumnPtr col = column(11);
    EXPECT_EQ(11, col->index());
    EXPECT_EQ("Max_HDOP", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(5, col->length());
    EXPECT_EQ(1, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column13_check) {
    DbfColumnPtr col = column(12);
    EXPECT_EQ(12, col->index());
    EXPECT_EQ("Corr_Type", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(36, col->length());
}

TEST_F(Dbase03ColumnFixture, column14_check) {
    DbfColumnPtr col = column(13);
    EXPECT_EQ(13, col->index());
    EXPECT_EQ("Rcvr_Type", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(36, col->length());
}

TEST_F(Dbase03ColumnFixture, column15_check) {
    DbfColumnPtr col = column(14);
    EXPECT_EQ(14, col->index());
    EXPECT_EQ("GPS_Date", col->name());
    EXPECT_EQ(DbfColumn::kDate, col->type());
    EXPECT_EQ(8, col->length());
}

TEST_F(Dbase03ColumnFixture, column16_check) {
    DbfColumnPtr col = column(15);
    EXPECT_EQ(15, col->index());
    EXPECT_EQ("GPS_Time", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(10, col->length());
}

TEST_F(Dbase03ColumnFixture, column17_check) {
    DbfColumnPtr col = column(16);
    EXPECT_EQ(16, col->index());
    EXPECT_EQ("Update_Sta", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(36, col->length());
}

TEST_F(Dbase03ColumnFixture, column18_check) {
    DbfColumnPtr col = column(17);
    EXPECT_EQ(17, col->index());
    EXPECT_EQ("Feat_Name", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase03ColumnFixture, column19_check) {
    DbfColumnPtr col = column(18);
    EXPECT_EQ(18, col->index());
    EXPECT_EQ("Datafile", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase03ColumnFixture, column20_check) {
    DbfColumnPtr col = column(19);
    EXPECT_EQ(19, col->index());
    EXPECT_EQ("Unfilt_Pos", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(10, col->length());
    EXPECT_EQ(0, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column21_check) {
    DbfColumnPtr col = column(20);
    EXPECT_EQ(20, col->index());
    EXPECT_EQ("Filt_Pos", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(10, col->length());
    EXPECT_EQ(0, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column22_check) {
    DbfColumnPtr col = column(21);
    EXPECT_EQ(21, col->index());
    EXPECT_EQ("Data_Dicti", col->name());
    EXPECT_EQ(DbfColumn::kCharacter, col->type());
    EXPECT_EQ(20, col->length());
}

TEST_F(Dbase03ColumnFixture, column23_check) {
    DbfColumnPtr col = column(22);
    EXPECT_EQ(22, col->index());
    EXPECT_EQ("GPS_Week", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(6, col->length());
    EXPECT_EQ(0, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column24_check) {
    DbfColumnPtr col = column(23);
    EXPECT_EQ(23, col->index());
    EXPECT_EQ("GPS_Second", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(12, col->length());
    EXPECT_EQ(3, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column25_check) {
    DbfColumnPtr col = column(24);
    EXPECT_EQ(24, col->index());
    EXPECT_EQ("GPS_Height", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(16, col->length());
    EXPECT_EQ(3, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column26_check) {
    DbfColumnPtr col = column(25);
    EXPECT_EQ(25, col->index());
    EXPECT_EQ("Vert_Prec", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(16, col->length());
    EXPECT_EQ(1, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column27_check) {
    DbfColumnPtr col = column(26);
    EXPECT_EQ(26, col->index());
    EXPECT_EQ("Horz_Prec", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(16, col->length());
    EXPECT_EQ(1, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column28_check) {
    DbfColumnPtr col = column(27);
    EXPECT_EQ(27, col->index());
    EXPECT_EQ("Std_Dev", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(16, col->length());
    EXPECT_EQ(6, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column29_check) {
    DbfColumnPtr col = column(28);
    EXPECT_EQ(28, col->index());
    EXPECT_EQ("Northing", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(16, col->length());
    EXPECT_EQ(3, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column30_check) {
    DbfColumnPtr col = column(29);
    EXPECT_EQ(29, col->index());
    EXPECT_EQ("Easting", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(16, col->length());
    EXPECT_EQ(3, col->decimal());
}

TEST_F(Dbase03ColumnFixture, column31_check) {
    DbfColumnPtr col = column(30);
    EXPECT_EQ(30, col->index());
    EXPECT_EQ("Point_ID", col->name());
    EXPECT_EQ(DbfColumn::kNumber, col->type());
    EXPECT_EQ(9, col->length());
    EXPECT_EQ(0, col->decimal());
}










