#ifndef CITY_H_
#define CITY_H_

#include "Skill.h"
#include "Employee.h"
#include "Manager.h"
#include "exceptions.h"
#include "Workplace.h"
#include "Faculty.h"
#include <stdexcept>
#include <map>

using std::map;
using std::pair;

namespace mtm
{
    class City
    {
        private:
            const string name;
            map<const int, Citizen* const> citizens;
            map<const int, Employee> employees;
            map<const int ,Manager> managers;
            map<const int, Workplace> work_places;
            map<const int, Faculty<Condition> > faculties;
        public:
            //c'tors and d'tor
            /**
             * @brief Construct a new City with the given name
             * 
             * @param name - city name
             */
            City(const string name);

            /**
             * @brief Destroy the City object
             * 
             */
            ~City() = default;

            /**
             * @brief Copy construct a new City object
             * 
             * @param city - city to be copied
             */
            City(const City& city) = default;

            //add methods
            /**
             * @brief adds a new employee to the city with the given parameters.
             * throw CitizenAlreadyExists if the employee was already added to the city.
             * 
             * @param id - id of employee to add.
             * @param first_name - first name of employee to add.
             * @param last_name - last name of employee to add.
             * @param birth_year - birth year of employee to add.
             */
            void addEmployee(const int id, const string first_name, const string last_name, const int birth_year);

            /**
             * @brief adds a new manager to the city with the given parameters.
             * throw CitizenAlreadyExists if the employee was already added to the city.
             * 
             * @param id - id of manager to add.
             * @param first_name - first name of manager to add.
             * @param last_name - last name of manager to add.
             * @param birth_year - birth year of manager to add.
             */
            void addManager(const int id, const string first_name, const string last_name, const int birth_year);
            
            /**
             * @brief adds a new faculty to the city with the given parameters.
             * throw FacultyAlreadyExists if the faculty was already added to the city. 
             * 
             * @param id - faculty id
             * @param skill - skill taught at the faculty
             * @param add_points - points added to the score of employees that were taught at the faculty.
             * @param admission_condition - faculty admission condition.
             */
            void addFaculty(const int id, const Skill skill, const unsigned int add_points, 
                            Condition *admission_condition);

            /**
             * @brief Create a new Workplace at the city.
             * throws WorkplaceAlreadyExists if the workplace was already added to the city. 
             * 
             * @param id - workplace id.
             * @param name - workplace name.
             * @param workers_salary - workers salary at the workplace.
             * @param managers_salary - managers salary at the workplace.
             */
            void createWorkplace(const int id, const string name, 
                                const unsigned int workers_salary,const unsigned int managers_salary);
            
            /**
             * @brief Tries to teach the employee with the given id at the faculty with the given id.
             * If the employee does not exist, throw EmployeeDoesNotExist.
             * If the faculty does not exist, throw FacultyDoesNotExist.
             * 
             * @param employee_id - Id of the employee to be taught.
             * @param faculty_id - Id of teaching faculty.
             */
            void teachAtFaculty(const int employee_id, const int faculty_id);
            
            //employment methods
            /**
             * @brief Hires an employee with the given employee, that fulfullis the hiring condition,
             * to the group of the manager with the given id, at the workplace with the given id.
             * If the process fails, throw the following exceptions:
             * EmployeeDoesNotExist - the employee does not exist in the city.
             * ManagerDoesNotExist - the manager does not exist in the city.
             * WorkplaceDoesNotExist - the workplace does not exist in the city.
             * 
             * @tparam Condition - hiring condition function object.
             * @param hiring_condition - Hiring condition the employee need to fulfill in order to be hired.
             * @param employee_id - Id of the employee to hire.
             * @param manager_id - Id of the manager the employee will join their group.
             * @param Workplace_id - Id of the hiring workplace.
             */
            template <class Condition>
            void hireEmployeeAtWorkplace(Condition hiring_condition, const int employee_id, 
                                         const int manager_id, const int Workplace_id)
            {
                try{
                    citizens.at(employee_id);
                }
                catch(std::out_of_range& e){
                    throw mtm::EmployeeDoesNotExist();
                }
                try{
                    citizens.at(manager_id);
                }
                catch(std::out_of_range& e){
                    throw mtm::ManagerDoesNotExist();
                }
                try{
                    work_places.at(Workplace_id);
                }
                catch(std::out_of_range& e){
                    throw mtm::WorkplaceDoesNotExist();
                }
                (work_places.at(Workplace_id)).hireEmployee(hiring_condition, &(employees.at(employee_id)), manager_id);
            }
            
            /**
             * @brief Tries to employ the manager with the given id, to the workplace with the given id.
             * Throws the following exceptions if the process fails:
             * ManagerDoesNotExist - the manager does not exist in the city.
             * WorkplaceDoesNotExist - the workplace does not exist in the city.
             * 
             * @param manager_id - id of the manager to hire. 
             * @param Workplace_id - hiring workplace id.
             */
            void hireManagerAtWorkplace(const int manager_id, const int Workplace_id);

            /**
             * @brief Removes the employee with the given id from the manager's group at the given workplace.
             * If the process fails, throw the following exceptions:
             * EmployeeDoesNotExist - the employee does not exist in the city.
             * ManagerDoesNotExist - the manager does not exist in the city.
             * WorkplaceDoesNotExist - the workplace does not exist in the city.
             * 
             * @param employee_id 
             * @param manager_id 
             * @param Workplace_id 
             */
            void fireEmployeeAtWorkplace(const int employee_id, const int manager_id, const int Workplace_id);

            /**
             * @brief Fires the manager with the given id and their group, from the workplace with the given id.
             * Throws the following exceptions if the process fails:
             * ManagerDoesNotExist - the manager does not exist in the city.
             * WorkplaceDoesNotExist - the workplace does not exist in the city.
             * 
             * @param manager_id 
             * @param Workplace_id 
             */
            void fireManagerAtWorkplace(const int manager_id, const int Workplace_id);

            /**
             * @brief Returns the id of the Workplace the employee with the id of employee_id works in
             * 
             * @param employee_id - employee whose Workplace id we need to return
             * @return the Workplace id of the employee's Workplace or -1 if unemployed 
             */
            int findWorkplaceOfEmployee(const int employee_id);

            /**
             * @brief Checks if the employees with the given Ids are working at the same workplace.
             * throws EmployeeDoesNotExist if either of the employees does not exist at the city.
             * 
             * @param employee1_id - id of employee 1.
             * @param employee2_id - id of employee 2.
             * @return true if the employees are working at the same workplace.
             * @return false if the employees are not working at the same workplace.
             */
            bool isWorkingInTheSameWorkplace(const int employee1_id, const int employee2_id);

            //print methods
            /**
             * @brief Prints a short description of all the citizens with a salary greater or equal
             * to the given salary, and returns the number of those citizens.
             * 
             * @param os - ostream to print to.
             * @param salary - Lower bound of the citizens' salaries.
             * @return Number of citizens with a salary equal or greater than the given salary.
             */
            int getAllAboveSalary(std::ostream& os, const int salary) const;

            /**
             * @brief Prints a short desription of all the employees in the city 
             * that have the skill with given id.
             * 
             * @param os - ostream to print to.
             * @param skill_id - Id of a certain skill.
             */
            void printAllEmployeesWithSkill(std::ostream& os, const int skill_id);
    };
}

#endif /* CITY_H_ */