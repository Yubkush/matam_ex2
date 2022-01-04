#include "Skill.h"
#include "exceptions.h"

namespace mtm{
    Skill::Skill(const int id, const string name, int required_points):
    id(id), name(name), required_points(required_points)
    {

    }

    int Skill::getId() const
    {
        return id;
    }

    string Skill::getName() const
    {
        return name;
    }

    int Skill::getRequiredPoints() const
    {
        return required_points;
    }

    Skill Skill::operator++(int)
    {
        Skill before_increment = *this;
        required_points++;
        return before_increment;
    }

    Skill& Skill::operator+=(int add)
    {
        if(add<0){
            throw NegativePoints();
        }
        required_points += add;
        return *this;
    }

    ostream& operator<<(ostream& os, const Skill& skill)
    {
        os << skill.name << "\n";
        return os;
    }

    bool operator==(const Skill& skill_1, const Skill& skill_2)
    {
        return (skill_1.getId() == skill_2.getId());
    }

    bool operator<(const Skill& skill_1, const Skill& skill_2)
    {
        return (skill_1.getId() < skill_2.getId());
    }

    bool operator>(const Skill& skill_1, const Skill& skill_2)
    {
        return !(skill_1<skill_2);
    }

    bool operator<=(const Skill& skill_1, const Skill& skill_2)
    {
        return (skill_1<skill_2)||(skill_1==skill_2);
    }

    bool operator>=(const Skill& skill_1, const Skill& skill_2)
    {
        return (skill_1>skill_2)||(skill_1==skill_2);
    }

    bool operator!=(const Skill& skill_1, const Skill& skill_2)
    {
        return !(skill_1==skill_2);
    }

    Skill operator+(const Skill& skill ,int add)
    {
        if(add<0){
            throw NegativePoints();
        }
        Skill sum = skill;
        return sum += add;
    }

    Skill operator+(int add, const Skill& skill)
    {
        if(add<0){
            throw NegativePoints();
        }
        Skill sum = skill;
        return sum += add;
    }
};

