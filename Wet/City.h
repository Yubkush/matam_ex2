#ifndef CITY_H_
#define CITY_H_

#include "Skill.h"
#include "Employee.h"
#include "Manager.h"
#include "exceptions.h"
#include "WorkPlace.h"
#include "Faculty.h"
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
            map<const int, WorkPlace> work_places;
            map<const int, Faculty> faculties;
        public:
            //c'tors and d'tor
            City(const string name);
            ~City() = default;
            City(const City& city) = default;

            //add methods
            void addEmployee(const int id, const string first_name, const string last_name, const int birth_year);
            void addManager(const int id, const string first_name, const string last_name, const int birth_year);
            void addFaculty(const int id, const Skill skill, const unsigned int add_points, 
                            bool (*admissionCondition)(Employee*));
            void createWorkPlace(const int id, const string name, 
                                const unsigned int workers_salary,const unsigned int managers_salary);
            
            void teachAtFaculty(const int employee_id, const int faculty_id);
            
            //employment methods
            template <class Condition>
            void hireEmployeeAtWorkplace(Condition hiring_condition, const int employee_id, 
                                         const int manager_id, const int workplace_id)
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
                    work_places.at(workplace_id);
                }
                catch(std::out_of_range& e){
                    throw mtm::WorkplaceDoesNotExist();
                }
                (work_places.at(workplace_id)).hireEmployee(hiring_condition, &(employees.at(employee_id)), manager_id);
            }
            
            void hireManagerAtWorkplace(const int manager_id, const int workplace_id);
            void fireEmployeeAtWorkplace(const int employee_id, const int manager_id, const int workplace_id);
            void fireManagerAtWorkplace(const int manager_id, const int workplace_id);
            /**
             * @brief Returns the id of the workplace the employee with the id of employee_id works in
             * 
             * @param employee_id - employee whose workplace id we need to return
             * @return the workplace id of the employee's workplace or -1 if unemployed 
             */
            int findWorkPlaceOfEmployee(const int employee_id);
            bool isWorkingInTheSameWorkplace(const int employee1_id, const int employee2_id);

            //print methods
            int printAllAboveSalary(std::ostream& os, const int salary) const;
            void printAllEmployeesWithSkill(std::ostream& os, const int skill_id);
    };
}

#endif /* CITY_H_ */