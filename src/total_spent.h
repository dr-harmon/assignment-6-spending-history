#pragma once

#include "company.h"
#include "money.h"

class TotalSpent {
public:
    TotalSpent(const Company& company, const Money& amount);
    const Company& getCompany() const;
    const Money& getAmount() const;
    bool operator ==(const TotalSpent& other) const;
    bool operator >(const TotalSpent& other) const;
private:
    Company company;
    Money amount;
};
