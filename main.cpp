#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <boost/filesystem/operations.hpp>
#include "DbfTable.h"
#include "Version.h"


using namespace std;

typedef enum Mode {
    kVersion,
    kSummary,
    kCsv
} Mode;

void print_usage() {
    cout << "usage: dbf2csv [-h|-v|-s|-c|-k] filename" << endl;
    cout << "  -a = append CSV header and data (format: '<header><separator><data>', separator: \\t, \\r, \\n, ;)" << endl;
    cout << "  -c = create a CSV file" << endl;
    cout << "  -h = print this message" << endl;
    cout << "  -k = skip deleted records (default: true)" << endl;
    cout << "  -l = output csv header names in lowercase (default: false)" << endl;
    cout << "  -s = print summary information" << endl;
    cout << "  -v = print the program version" << endl;
}

int main(int argc, char *argv[]) {
    Mode mode = kVersion;
    bool skip_deleted = true;
    bool lowercase_header_names = false;
    std::string append_csv_header;
    std::string append_csv_data;

    int opt;
    while ((opt = getopt(argc, argv, "a:chk:l:sv")) != -1) {
        switch (opt) {
            case 'a': {
                std::vector<std::string> parts;
                boost::split(parts, optarg, boost::is_any_of("\t\r\n;"));
                if (parts.size() == 2) {
                    append_csv_header = parts[0];
                    append_csv_data = parts[1];
                }
                else {
                    cerr << "Invalid append option: '" << optopt << "'" << endl;
                    return 1;
                }
                break;
            }
            case 'c':
                mode = kCsv;
                break;
            case 'h':
                print_usage();
                return 0;
            case 'k':
                skip_deleted = (optarg[0] == 'Y' || optarg[0] == 'y');
                break;
            case 'l':
                lowercase_header_names = (optarg[0] == 'Y' || optarg[0] == 'y');
                break;
            case 's':
                mode = kSummary;
                break;
            case 'v':
                mode = kVersion;
                break;
            default:
                cerr << "Unrecognized option: '" << optopt << "'" << endl;
                print_usage();
                return 1;
        }
    }

    if (mode == kVersion) {
        cout << "dbf2csv version: " << Version << endl;
        print_usage();
        return 0;
    }

    string dbf_filename = argv[optind];
    DbfTablePtr dbf_table = DbfTablePtr(new DbfTable(dbf_filename, skip_deleted));

    if (!dbf_table->good()) {
        cerr << "Unable to open file: " << dbf_filename << endl;
        return 1;
    }

    if (mode == kSummary) {
        cout << "Database: " << dbf_filename << endl;

        const DbfHeaderPtr header = dbf_table->header();
        cout << "Type: (" << hex << header->version() << dec << ") " << header->version_description() << endl;
        cout << "Memo File: " << (dbf_table->has_memo_file() ? "true" : "false") << endl;
        cout << "Records: " << header->record_count() << endl;
        cout << "Last updated at: " << header->updated_at() << endl;
        cout << endl;

        cout << "Fields:" << endl;
        cout << "Name             Type       Length     Decimal" << endl;
        cout << "------------------------------------------------------------------------------" << endl;

        std::vector<DbfColumnPtr> columns = dbf_table->columns();
        for (auto it = std::begin(columns); it != std::end(columns); ++it) {
            DbfColumnPtr column(*it);
            cout << left << setw(17) << column->name();
            cout << left << setw(11) << (char)column->type();
            cout << left << setw(11) << column->length();
            cout << left << column->decimal();
            cout << endl;
        }
    }
    else {
        dbf_table->to_csv(cout, lowercase_header_names, append_csv_header, append_csv_data);
    }

    return 0;
}

