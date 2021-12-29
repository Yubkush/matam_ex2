#include "Citizen.h"

using mtm::Citizen;
using std::string;

namespace mtm
{
    Citizen::Citizen(const int id, const string first_name, const string last_name, const int birth_year):
        id(id), first_name(first_name), last_name(last_name), birth_year(birth_year)
    {
        
    }
        
    int Citizen::getId() const
    {
        return id;
    }
    string Citizen::getFirstName() const
    {
        return first_name;
    }
    string Citizen::getLastName() const
    {
        return last_name;
    }
    int Citizen::getBirthYear() const
    {
        return birth_year;
    }
    
    bool operator==(const Citizen& citizen_1, const Citizen& citizen_2)
    {
        return citizen_1.getId() == citizen_2.getId();
    }
    bool operator>(const Citizen& citizen_1, const Citizen& citizen_2)
    {
        return citizen_1.getId() > citizen_2.getId();
    }
    bool operator<(const Citizen& citizen_1, const Citizen& citizen_2)
    {
        return citizen_1.getId() < citizen_2.getId();
    }
    bool operator<=(const Citizen& citizen_1, const Citizen& citizen_2)
    {
        return !(citizen_1 > citizen_2);
    }
    bool operator>=(const Citizen& citizen_1, const Citizen& citizen_2)
    {
        return !(citizen_1 < citizen_2);
    }
    bool operator!=(const Citizen& citizen_1, const Citizen& citizen_2)
    {
        return !(citizen_1 == citizen_2);
    }
}