#pragma once

#include "company.h"
#include "money.h"
#include "total_spent.h"

#include <vector>

class SpendingHistory {
public:
    void addReceipt(const Company& company, const Money& amount);
    std::vector<TotalSpent> getTotals() const;
};
