#include "company.h"

using namespace std;

Company::Company(const string& _name, const string& _city) : name(_name), city(_city)
{
}

const string& Company::getName() const
{
    return name;
}

const string& Company::getCity() const
{
    return city;
}

bool Company::operator ==(const Company& other) const
{
    return (name == other.name) && (city == other.city);
}

ostream& operator<<(ostream& os, const Company& company)
{
    os << company.getName();
    return os;
}
