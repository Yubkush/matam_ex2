#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Citizen.h"
#include "Skill.h"
#include <set>

using mtm::Skill;
using mtm::Citizen;
using std::set;

namespace mtm
{
    class Employee : public Citizen
    {
        private:
            int salary;
            int score;
            set<Skill> skill_set;
        public:
            //c'tors and d'tor
            Employee(const int id, const string first_name, const string last_name, const int birth_year);
            ~Employee() = default;
            Employee(const Employee& employee) = default;
            
            //getters and setters
            int getSalary() const;
            int getScore() const;
            void setSalary(const int salary_to_add);
            void setScore(const int score_to_add);
            
            //skill methods
            void learnSkill(const Skill& skill_to_learn);
            void forgetSkill(const int skill_id);
            bool hasSkill(const int skill_id) const;

            //print functions
            std::ostream& printShort(std::ostream& os) const;
            std::ostream& printLong(std::ostream& os) const;

            Employee* clone() const;
    };
}

#endif /* EMPLOYEE_H_ */