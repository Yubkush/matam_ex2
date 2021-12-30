#include "WorkPlace.h"
#include "exceptions.h"

using mtm::WorkPlace;

namespace mtm
{
    WorkPlace::WorkPlace(const int id, const string name, 
                    const unsigned int workers_salary,const unsigned int managers_salary):
                    id(id), name(name), workers_salary(workers_salary), managers_salary(managers_salary), managers()
    {
        
    }
    
    int WorkPlace::getID() const
    {
        return id;
    }

    string WorkPlace::getName() const
    {
        return name;
    }

    int WorkPlace::getWorkersSalary() const
    {
        return workers_salary;
    }

    int WorkPlace::getManagersSalary() const
    {
        return managers_salary;
    }

    Manager* WorkPlace::findManagerById(const int manager_id) const
    {
        for(Manager* manager : managers){
            if(manager->getId() == manager_id){
                return manager;
            }
        }
        return NULL;
    }

    bool WorkPlace::isManagerInWorkplace(const int manager_id) const
    {
        if(findManagerById(manager_id) != NULL){
            return true;
        }
        return false;
    }

    void WorkPlace::fireEmployee(const int employee_id, const int manager_id)
    {
        if(!isManagerInWorkplace(manager_id)){
            throw mtm::ManagerIsNotHired();
        }
        Manager* manager_of_employee = findManagerById(manager_id);
        manager_of_employee->removeEmployee(employee_id);
    }

    void WorkPlace::hireManager(Manager* const manager_to_hire)
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

    void WorkPlace::fireManager(const int manager_id_to_fire)
    {
        if(!isManagerInWorkplace(manager_id_to_fire)){
            throw mtm::ManagerIsNotHired();
        }
        Manager* manager_to_fire = findManagerById(manager_id_to_fire);
        manager_to_fire->removeAllEmployees();
        manager_to_fire->setSalary(-(manager_to_fire->getSalary()));
        managers.erase(manager_to_fire);
    }
    
    ostream& operator<<(ostream& os, const WorkPlace& workplace)
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