#ifndef FACULTY_H_
#define FACULTY_H_

#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"
#include "exceptions.h"

namespace mtm 
{
    /**
     * @brief Class that is used for the Faculty container inside city
     * 
     */
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
            Condition_T *admission_condition;
        public:
            //c'tors and d'tor
            /**
             * @brief Construct a new Faculty object
             * 
             * @param id - Faculty Id
             * @param skill - Skill that will be taught at the faculty
             * @param add_points - amount of points to add to the employee's score if the faculty teaches him succesfully
             * @param admission_condition - Condition that employees need to fulfill in order to learn at the faculty
             */
            Faculty(const int id, const Skill skill,
                        const unsigned int add_points, Condition_T *admission_condition):
                    id(id), skill(skill), add_points(add_points), admission_condition(admission_condition)
            {

            }
            /**
             * @brief Destroy the Faculty object
             * 
             */
            ~Faculty() = default;

            /**
             * @brief Copy constructs a new faculty object
             * 
             * @param faculty - faculty to copy
             */
            Faculty (const Faculty& faculty) = default;
            
            //getters and setters
            /**
             * @brief Get the Id of the faculty
             * 
             * @return int - id
             */
            int getId() const
            {
                return id;
            }

            /**
             * @brief Get the Skill that the faculty teaches
             * 
             * @return Skill to be taught
             */
            Skill getSkill() const
            {
                return skill;
            }
            
            /**
             * @brief Get the amount of Points the faculty adds to employees that learn at the faculty
             * 
             * @return int - amount of points
             */
            int getAddedPoints() const
            {
                return add_points;
            }
            
            /**
             * @brief adds the skill that is taught by the faculty to the employee's skill set, and increases their score
             * if the employee does not fulfill the admission condition, throw EmployeeNotAccpted exception 
             * 
             * @param employee 
             */
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