#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"
#include "Citizen.h"
#include "pointer_compare.h"

using mtm::Citizen;
using mtm::Employee;

namespace mtm
{
    /**
     * Manager class declaration
     */
    class Manager: public Citizen
    {
        private:
            int salary;
            set<Employee*, mtm::PointerCompare> employees;
        public:
            //c'tor
            Manager(const int id, const string first_name, const string last_name, const int birth_year);
            //d'tor
            ~Manager() = default;
            //copy c'tor
            Manager(const Manager& manager) = default;

            /**
             * @brief Get the Salary object
             * 
             * @return int 
             */
            int getSalary() const override;
            /**
             * @brief Set the Salary object
             * 
             * @param salary_to_add added to current salary
             */
            void setSalary(const int salary_to_add);

            //manage employees
            /**
             * @brief add employee to work under manager
             * 
             * @param employee_to_add employee added
             */
            void addEmployee(Employee* const employee_to_add);
            /**
             * @brief remove employee from manager's responsibility 
             * 
             * @param id_to_remove employee id to remove
             */
            void removeEmployee(const int id_to_remove);
            /**
             * @brief remove all employees under manager
             * 
             */
            void removeAllEmployees();
            /**
             * @brief check if employee work under the manager
             * 
             * @param employee_id to check
             * @return true if employee work under the manager
             * @return false if employee doesn't work under the manager
             */
            bool isEmployeeEmployed(const int employee_id) const;

            //print
            /**
             * @brief prints manager full name and salary
             * 
             * @param os output stream which we print to
             * @return std::ostream& 
             */
            std::ostream& printShort(std::ostream& os) const;
            /**
             * @brief prints manager full name, id, birthyear, salary and all employees
             * 
             * @param os output stream which we print to
             * @return std::ostream& 
             */
            std::ostream& printLong(std::ostream& os) const;
            /**
             * @brief create a copy of manager
             * 
             * @return Manager* 
             */
            Manager* clone() const;
    };
}

#endif /* MANAGER_H_ */