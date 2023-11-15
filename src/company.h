#pragma once

#include <ostream>
#include <string>

class Company {
public:
    Company(const std::string& name, const std::string& city = "");
    const std::string& getName() const;
    const std::string& getCity() const;
    bool operator ==(const Company& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Company& company);
private:
    std::string name;
    std::string city;
};
