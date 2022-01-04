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
            /**
             * @brief Construct a new Employee object
             * 
             * @param id - Employee's ID
             * @param first_name - Employee's first name
             * @param last_name - Employee's last name
             * @param birth_year - Employee's birth year
             */
            Employee(const int id, const string first_name, const string last_name, const int birth_year);

            /**
             * @brief Destroy the Employee object
             * 
             */
            ~Employee() = default;

            /**
             * @brief Copy constructor
             * 
             * @param employee - Employee to copy
             */
            Employee(const Employee& employee) = default;
            
            //getters and setters
            /**
             * @brief Get the salary of the employee
             * 
             * @return int - employee salary
             */
            int getSalary() const override;
            /**
             * @brief Get the score of the employee
             * 
             * @return int - employee score
             */
            int getScore() const;
            /**
             * @brief Set the Salary of the employee
             * 
             * @param salary_to_add - amount to add to the employee's salary
             */
            void setSalary(const int salary_to_add);
            /**
             * @brief Set the Salary of the employee
             * 
             * @param salary_to_add - amount to add to the employee's salary
             */
            void setScore(const int score_to_add);
            
            //skill methods
            /**
             * @brief tries to add the given skill to the employee's skill set.
             * If the employee has this skill already, the function throws SkillAlreadyLearned exception.
             * if the employee can not get this skill, throw CanNotLearnSkill exception
             * 
             * @param skill - Skill to add to the employee's skill set
             */
            void learnSkill(const Skill& skill_to_learn);
            
            /**
             * @brief Removes the skill with the given ID fromthe employee's skill set.
             * If the employee doesn't have that skill, throw DidNotLearnSkill exception.
             * 
             * @param skill_id - Id of the skill that needs to be removed
             */
            void forgetSkill(const int skill_id);

            /**
             * @brief checks if the employee has the skill with the given id.
             * 
             * @param skill_id - id of the skill to check
             * @return true - if the employee has that skill
             * @return false - if the employee doesn't have that skill. 
             */
            bool hasSkill(const int skill_id) const;

            //print functions
            /**
             * @brief Print a short description of the employee.
             * 
             * @param os - the ostream to print the description to
             * @return the given ostream.
             */
            std::ostream& printShort(std::ostream& os) const;

            /**
             * @brief Print a longer description of the employee.
             * 
             * @param os - the ostream to print the description to
             * @return the given ostream.
             */
            std::ostream& printLong(std::ostream& os) const;

            /**
             * @brief Clones the employee
             * 
             * @return Employee* - pointer to the new employee created
             */
            Employee* clone() const;
    };
}

#endif /* EMPLOYEE_H_ */