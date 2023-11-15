#include "spending_history.h"
#include "csv.h"
#include "money.h"

#include <functional>
#include <iostream>
#include <string>

using namespace std;

void loadReceipts(function<void(const Company&,const Money&)> callback)
{
    io::CSVReader<2> in(RECEIPTS_PATH);
    in.read_header(io::ignore_extra_column, "company", "receipt_total");
    string companyName;
    string receiptTotal;
    while (in.read_row(companyName, receiptTotal)) {
		callback(Company(companyName), Money(receiptTotal));
    }
}

int main()
{
	SpendingHistory history;

	loadReceipts([&history](const Company& company, const Money& receiptTotal) {
		history.addReceipt(company, receiptTotal);
	});

	for (const auto& totalSpend : history.getTotals()) {
		cout << totalSpend.getCompany() << ": " << totalSpend.getAmount() << endl;
	}

	return EXIT_SUCCESS;
}
