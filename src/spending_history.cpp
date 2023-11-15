#include "spending_history.h"

#include <algorithm>
#include <functional>

using namespace std;

void SpendingHistory::addReceipt(const Company& company, const Money& amount)
{
    receipts[company] += amount;
}

vector<TotalSpent> SpendingHistory::getTotals() const
{
    vector<TotalSpent> total;
    for (const auto& p : receipts) {
        total.emplace_back(p.first, p.second);
    }
    sort(total.begin(), total.end(), greater<TotalSpent>());
    return total;
}
