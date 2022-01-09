#include "Workplace.h"
#include "exceptions.h"

using mtm::Workplace;

namespace mtm
{
    Workplace::Workplace(const int id, const string name, 
                    const unsigned int workers_salary,const unsigned int managers_salary):
                    id(id), name(name), workers_salary(workers_salary), managers_salary(managers_salary), managers()
    {
        
    }
    
    int Workplace::getId() const
    {
        return id;
    }

    string Workplace::getName() const
    {
        return name;
    }

    int Workplace::getWorkersSalary() const
    {
        return workers_salary;
    }

    int Workplace::getManagersSalary() const
    {
        return managers_salary;
    }

    Manager* Workplace::findManagerById(const int manager_id) const
    {
        for(Manager* manager : managers){
            if(manager->getId() == manager_id){
                return manager;
            }
        }
        return NULL;
    }

    bool Workplace::isManagerInWorkplace(const int manager_id) const
    {
        if(findManagerById(manager_id) != NULL){
            return true;
        }
        return false;
    }

    int Workplace::getManagerIdOfEmployee(const int employee_id) const
    {
        for(Manager* manager : managers){
            if(manager->isEmployeeEmployed(employee_id)){
                return manager->getId();
            }
        }
        throw EmployeeIsNotHired();
    }

    void Workplace::emptyWorkPlace()
    {
        managers.clear();
    }

    void Workplace::hireEmployeeWithoutCondition(Employee* const employee_to_hire, const int manager_id)
    {
        Manager* manager_of_employee = findManagerById(manager_id);
        manager_of_employee->addEmployee(employee_to_hire);
        employee_to_hire->setSalary(workers_salary);
    }

    void Workplace::fireEmployee(const int employee_id, const int manager_id)
    {
        if(!isManagerInWorkplace(manager_id)){
            throw mtm::ManagerIsNotHired();
        }
        Manager* manager_of_employee = findManagerById(manager_id);
        manager_of_employee->removeEmployee(employee_id);
    }

    void Workplace::hireManager(Manager* const manager_to_hire)
    {
        if(managers.find(manager_to_hire) != managers.end()){
            throw mtm::ManagerAlreadyHired();
        }
        if(manager_to_hire->getSalary() > 0){
            throw mtm::CanNotHireManager();
        }
        managers.insert(manager_to_hire);
        manager_to_hire->setSalary(managers_salary);
    }

    void Workplace::fireManager(const int manager_id_to_fire)
    {
        if(!isManagerInWorkplace(manager_id_to_fire)){
            throw mtm::ManagerIsNotHired();
        }
        Manager* manager_to_fire = findManagerById(manager_id_to_fire);
        manager_to_fire->removeAllEmployees();
        manager_to_fire->setSalary(-(manager_to_fire->getSalary()));
        managers.erase(manager_to_fire);
    }
    
    ostream& operator<<(ostream& os, const Workplace& workplace)
    {
        os << "Workplace name - " << workplace.name;
        if(!workplace.managers.empty()){
            os << " Groups:";
        }
        os << "\n";
        for(Manager* manager : workplace.managers){
            os << "Manager ";
            manager->printLong(os);
        }
        return os;
    }
}