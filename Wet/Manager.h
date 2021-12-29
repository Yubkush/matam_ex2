#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"
#include "Citizen.h"

using mtm::Citizen;
using mtm::Employee;

namespace mtm
{
    class Manager: public Citizen
    {
        private:
            int salary;
            set<Employee*> employees;
        public:
            //c'tors and d'tor
            Manager(const int id, const string first_name, const string last_name, const int birth_year);
            ~Manager() = default;
            Manager(const Manager& manager) = default;

            //getters and setters
            int getSalary() const;
            void setSalary(const int salary_to_add);

            //manage employees
            void addEmployee(Employee* const employee_to_add);
            void removeEmployee(const int id_to_remove);
            void removeAllEmployees();

            //print
            std::ostream& printShort(std::ostream& os) const;
            std::ostream& printLong(std::ostream& os) const;
            
            Manager* clone() const;
    };
}

#endif /* MANAGER_H_ */