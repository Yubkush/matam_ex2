#ifndef WORKPLACE_H_
#define WORKPLACE_H_

#include "Employee.h"
#include "Manager.h"
#include "exceptions.h"
#include "pointer_compare.h"

using mtm::Manager;
using mtm::Employee;
using std::string;

namespace mtm
{
    class Workplace
    {
        private:
            const int id;
            const string name;
            const unsigned int workers_salary;
            const unsigned int managers_salary;
            set<Manager*, mtm::PointerCompare> managers;
        public:

            //c'tors and d'tor
            /**
             * @brief Construct a new Work Place object
             * 
             * @param id - Workplace id
             * @param name - Workplace name
             * @param workers_salary - Salary granted to the workplace's employees
             * @param managers_salary - Salary granted to the workplace's managers
             */
            Workplace(const int id, const string name, 
                    const unsigned int workers_salary,const unsigned int managers_salary);

            /**
             * @brief Destroy the Workplace object
             * 
             */
            ~Workplace() = default;

            /**
             * @brief Copy construct a new Workplace object
             * 
             * @param workplace - workplace to be copied
             */
            Workplace(const Workplace& workplace) = default;

            //getters
            /**
             * @brief return workplace id
             * 
             * @return int - workplace id
             */
            int getId() const;

            /**
             * @brief return workplace name
             * 
             * @return string - workplace name
             */
            string getName() const;

            /**
             * @brief Get the Workers Salary 
             * 
             * @return int - workers salary
             */
            int getWorkersSalary() const;

            /**
             * @brief Get the Managers Salary
             * 
             * @return int - managers salary
             */
            int getManagersSalary() const;

            /**
             * @brief return a pointer to a manager with the given id, and NULL if manager not found.
             * 
             * @param manager_id - id of manager to find
             * @return Manager* - manager with the given id if found, or NULL otherwise.
             */
            Manager* findManagerById(const int manager_id) const;

            /**
             * @brief checks if a manager with the given id is employed at the workplace
             * 
             * @param manager_id - manager to find
             * @return true - manager is employed at the workplace
             * @return false - manager is not employed at the workplace
             */
            bool isManagerInWorkplace(const int manager_id) const;

            int getManagerIdOfEmployee(const int employee_id) const;
            void emptyWorkPlace();
            void hireEmployeeWithoutCondition(Employee* const employee_to_hire, const int manager_id);

            //employee methods
            /**
             * @brief Adds a given employee that fulfills the recruitment condition, 
             * to the group of a manager with the given Id. if the process fails, throw the following exceptions:
             * EmployeeNotSelected - The employee does not fulfill the recruitment condition
             * ManagerIsNotHired - The manager does not work at the worplace
             * EmployeeAlreadyHired- The employee already works in the workplace
             * 
             * @tparam Condition - recruitment condition
             * @param condition - condition the employee needs to fulfill
             * @param employee_to_hire - pointer to the hired employee
             * @param manager_id - The manager that will be the employee's direct boss
             */
            template <class Condition>
            void hireEmployee(Condition& condition, 
                            Employee* const employee_to_hire, 
                            const int manager_id)
            {
                if(!condition(employee_to_hire)){
                    throw mtm::EmployeeNotSelected();
                }
                if(!isManagerInWorkplace(manager_id)){
                    throw mtm::ManagerIsNotHired();
                }
                Manager* manager_of_employee = findManagerById(manager_id);
                manager_of_employee->addEmployee(employee_to_hire);
                employee_to_hire->setSalary(workers_salary);
            }

            /**
             * @brief removes the employee with the given id from the group of the manager with the given id.
             * if the process fails, throws the following exceptions:
             * EmployeeIsNotHired - if the employee is not at the manager's group.
             * ManagerIsNotHired - if the manager does not work at the workplace.
             * 
             * @param employee_id - id of the employee to fire. 
             * @param manager_id - id of the employee's manager.
             */
            void fireEmployee(const int employee_id, const int manager_id);

            //manager methods
            /**
             * @brief Adds the given manager to the workplace.
             * if the process fails, throws the following exceptions:
             * ManagerAlreadyHired - if the manager already works at the workplace.
             * CanNotHireManager - if the manager already works at another workplace.
             * 
             * @param manager_to_hire - pointer to the manager to be hired
             */
            void hireManager(Manager* const manager_to_hire);

            /**
             * @brief fires the manager with the given id and their group from the workplace.
             * if the process fails, throws the following exceptions:
             * ManagerIsNotHired - if the manager was not hired by the company
             * 
             * @param manager_id_to_fire
             */
            void fireManager(const int manager_id_to_fire);

            /**
             * @brief Print workplace description, using the << operator.
             * 
             * @param os - ostream to print to.
             * @param workplace - workplace to print description of.
             * @return the given ostream.
             */
            friend ostream& operator<<(ostream& os, const Workplace& workplace);
    };
}

#endif /* WORKPLACE_H_ */