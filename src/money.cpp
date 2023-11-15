#include "money.h"

#include <iomanip>
#include <sstream>

using namespace std;

Money::Money(int cents)
{
    this->cents = cents;
}

Money::Money(const string& amount)
{
    string dollarStr = amount.substr(1, amount.find(".") - 1);
    string centsStr = amount.substr(amount.find(".") + 1);
    cents = stoi(dollarStr) * 100 + stoi(centsStr);
}

int Money::getCents() const
{
    return cents;
}

bool Money::operator <(const Money& other) const
{
    return cents < other.cents;
}

bool Money::operator >(const Money& other) const
{
    return cents > other.cents;
}

bool Money::operator ==(const Money& other) const
{
    return cents == other.cents;
}

Money& Money::operator +=(const Money& other)
{
    cents += other.cents;
    return *this;
}

ostream& operator<<(ostream& os, const Money& money)
{
    ostringstream ss;
    int cents = money.cents;
    if (cents < 0) {
        ss << "-";
        cents = -cents;
    }
    ss << "$"
       << (cents / 100)
       << "."
       << setw(2) << setfill('0')
       << (cents % 100);
    os << ss.str();
    return os;
}
