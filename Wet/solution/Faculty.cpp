#include "Faculty.h"
#include "exceptions.h"

using mtm::Faculty;
using mtm::Skill;

namespace mtm
{
    Faculty::Faculty(const int id, bool (*admissionCondition)(Employee*), const Skill skill,
                        const unsigned int add_points):
                    id(id), admissionCondition(admissionCondition), skill(skill), add_points(add_points)
    {
        
    }

    int Faculty::getId() const
    {
        return id;
    }
    Skill Faculty::getSkill() const
    {
        return skill;
    }
    int Faculty::getAddedPoints() const
    {
        return add_points;
    }
            
    void Faculty::teach(Employee* employee)
    {
        if(!admissionCondition(employee)){
            throw mtm::EmployeeNotAccepted();
        }
        employee->learnSkill(skill);
        employee->setScore(add_points);
    }

}