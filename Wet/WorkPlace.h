#ifndef WORKPLACE_H_
#define WORKPLACE_H_

#include "Employee.h"
#include "Manager.h"
#include "exceptions.h"

using mtm::Manager;
using mtm::Employee;
using std::string;

namespace mtm
{
    class WorkPlace
    {
        private:
            const int id;
            const string name;
            const unsigned int workers_salary;
            const unsigned int managers_salary;
            set<Manager*> managers;
        public:

            //c'tors and d'tor
            WorkPlace(const int id, const string name, 
                    const unsigned int workers_salary,const unsigned int managers_salary);
            ~WorkPlace() = default;
            WorkPlace(const WorkPlace& workplace) = default;

            //getters
            int getID() const;
            string getName() const;
            int getWorkersSalary() const;
            int getManagersSalary() const;

            bool isManagerInWorkplace(const int manager_id);
            Manager* findManagerById(const int manager_id);

            //employee methods
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
            void fireEmployee(const int employee_id, const int manager_id);

            //manager methods
            void hireManager(Manager* const manager_to_hire);
            void fireManager(const int manager_id_to_fire);

            friend ostream& operator<<(ostream& os, const WorkPlace& workplace);
    };
}

#endif /* WORKPLACE_H_ */