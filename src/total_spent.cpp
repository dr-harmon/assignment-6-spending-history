#include "total_spent.h"

using namespace std;

TotalSpent::TotalSpent(const Company& _company, const Money& _amount) : company(_company), amount(_amount)
{
}

const Company& TotalSpent::getCompany() const
{
    return company;
}

const Money& TotalSpent::getAmount() const
{
    return amount;
}

bool TotalSpent::operator ==(const TotalSpent& other) const
{
    return (company == other.company) && (amount == other.amount);
}
