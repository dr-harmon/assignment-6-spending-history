#pragma once

#include <ostream>
#include <string>

class Money {
public:
    Money() = default;
    Money(int cents);
    Money(const std::string& amount);
    int getCents() const;
    bool operator <(const Money& other) const;
    bool operator >(const Money& other) const;
	bool operator ==(const Money& other) const;
    Money& operator +=(const Money& other);
    friend std::ostream& operator<<(std::ostream& os, const Money& money);
private:
    int cents;
};
