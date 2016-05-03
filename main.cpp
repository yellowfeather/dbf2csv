#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "DbfTable.h"
#include "Version.h"


using namespace std;

typedef enum Mode {
    kVersion,
    kSummary,
    kCsv
} Mode;

void print_usage() {
    cerr << "usage: dbf2csv [-h|-v|-s|-c|] filename" << endl;
    cerr << "-h = print this message" << endl;
    cerr << "-v = print the program version" << endl;
    cerr << "-s = print summary information" << endl;
    cerr << "-c = create a CSV file" << endl;
    cerr << "-k = skip deleted records (default: true)" << endl;
}

int main(int argc, char *argv[]) {
    Mode mode;
    bool skip_deleted = true;

    int opt;
    while ((opt = getopt(argc, argv, "hvsck:")) != -1) {
        switch (opt) {
            case 'v':
                mode = kVersion;
                break;
            case 's':
                mode = kSummary;
                break;
            case 'c':
                mode = kCsv;
                break;
            case 'k':
                skip_deleted = (optarg[0] == 'Y' || optarg[0] == 'y');
                break;
            case 'h':
                print_usage();
                return 0;
            default:
                cerr << "Unrecognized option: '" << optopt << "'" << endl;
                print_usage();
                return 1;
        }
    }

    if (mode == kVersion) {
        cout << "dbf2csv version: " << Version << endl;
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
        cout << "Type: (" << hex << header->version() << ") " << header->version_description() << endl;
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
            cout << left << setw(11) << column->type();
            cout << left << setw(11) << column->length();
            cout << left << column->decimal();
            cout << endl;
        }
    }
    else if (mode == kCsv) {
        dbf_table->to_csv(cout);
    }

    return 0;
}

