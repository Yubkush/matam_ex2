#ifndef FACULTY_H_
#define FACULTY_H_

#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"
#include "exceptions.h"

namespace mtm 
{
    class Condition{
        public:
            virtual bool operator()(Employee* employee) = 0;
    }; 

    template <class Condition_T>
    class Faculty 
    {
        private:
            const int id;
            const Skill skill;
            const unsigned int add_points;
            Condition *admission_condition;
        public:
            //c'tors and d'tor
            Faculty(const int id, const Skill skill,
                        const unsigned int add_points, Condition *admission_condition):
                    id(id), skill(skill), add_points(add_points), admission_condition(admission_condition)
            {

            }
            ~Faculty() = default;
            Faculty (const Faculty& faculty) = default;
            
            //getters and setters
            int getId() const
            {
                return id;
            }

            Skill getSkill() const
            {
                return skill;
            }
            
            int getAddedPoints() const
            {
                return add_points;
            }
            
            void teach(Employee* employee)
            {
                if(!((*admission_condition)(employee))){
                    throw mtm::EmployeeNotAccepted();
                }
                employee->learnSkill(skill);
                employee->setScore(add_points);
            }
    };
}

#endif /* FACULTY_H_ */