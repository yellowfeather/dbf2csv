//
// Created by Chris Richards on 28/04/2016.
//

#include <gtest/gtest.h>
#include <DbfRecord.h>
#include <DbfTable.h>

class DbfRecordFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        dbf_table_ = DbfTablePtr(new DbfTable("/Users/chrisr/Development/ClionProjects/dbf2csv/dbf_tests/fixtures/dbase_03.dbf"));
    }

    virtual void TearDown() {
        dbf_table_->close();
    }

public:
    DbfRecordFixture() : Test() {
    }

    virtual ~DbfRecordFixture() {
    }

    DbfTablePtr dbf_table_;
};

TEST_F(DbfRecordFixture, record_count_check) {
    DbfHeaderPtr header(dbf_table_->header());
    int record_count = header->record_count();
    EXPECT_EQ(14, record_count);
}

TEST_F(DbfRecordFixture, record1_check) {
    DbfRecordPtr record(new DbfRecord(dbf_table_));
    dbf_table_->get_record(record);

    std::vector<boost::any> values(record->values());
    EXPECT_EQ(31, values.size());

    EXPECT_EQ("0507121", boost::any_cast<std::string>(values[0]));
    EXPECT_EQ("CMP", boost::any_cast<std::string>(values[1]));
    EXPECT_EQ("circular", boost::any_cast<std::string>(values[2]));
    EXPECT_EQ("12", boost::any_cast<std::string>(values[3]));
    EXPECT_EQ("", boost::any_cast<std::string>(values[4]));
    EXPECT_EQ("no", boost::any_cast<std::string>(values[5]));
    EXPECT_EQ("Good", boost::any_cast<std::string>(values[6]));
    EXPECT_EQ("", boost::any_cast<std::string>(values[7]));
    EXPECT_EQ("20050712", boost::any_cast<std::string>(values[8]));
    EXPECT_EQ("10:56:30am", boost::any_cast<std::string>(values[9]));
    EXPECT_EQ(5.2, boost::any_cast<double>(values[10]));
    EXPECT_EQ(2.0, boost::any_cast<double>(values[11]));
    EXPECT_EQ("Postprocessed Code", boost::any_cast<std::string>(values[12]));
    EXPECT_EQ("GeoXT", boost::any_cast<std::string>(values[13]));
    EXPECT_EQ("20050712", boost::any_cast<std::string>(values[14]));
    EXPECT_EQ("10:56:52am", boost::any_cast<std::string>(values[15]));
    EXPECT_EQ("New", boost::any_cast<std::string>(values[16]));
    EXPECT_EQ("Driveway", boost::any_cast<std::string>(values[17]));
    EXPECT_EQ("050712TR2819.cor", boost::any_cast<std::string>(values[18]));
    EXPECT_EQ(2, boost::any_cast<int>(values[19]));
    EXPECT_EQ(2, boost::any_cast<int>(values[20]));
    EXPECT_EQ("MS4", boost::any_cast<std::string>(values[21]));
    EXPECT_EQ(1331, boost::any_cast<int>(values[22]));
    EXPECT_EQ(226625.0, boost::any_cast<double>(values[23]));
    EXPECT_EQ(1131.323, boost::any_cast<double>(values[24]));
    EXPECT_EQ(3.1, boost::any_cast<double>(values[25]));
    EXPECT_EQ(1.3, boost::any_cast<double>(values[26]));
    EXPECT_EQ(0.897088, boost::any_cast<double>(values[27]));
    EXPECT_EQ(557904.898, boost::any_cast<double>(values[28]));
    EXPECT_EQ(2212577.192, boost::any_cast<double>(values[29]));
    EXPECT_EQ(401, boost::any_cast<int>(values[30]));
}
