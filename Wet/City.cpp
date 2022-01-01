#include "City.h"
#include "exceptions.h"

#define UNEMPLOYED -1

using mtm::City;

namespace mtm
{
    City::City(const string name): name(name), citizens(), employees(), managers(), work_places(), faculties()
    {

    }

    // City::~City()
    // {
    //     map<const int, Faculty<Condition>*>::iterator itr = faculties.begin();
    //     if (itr != faculties.end())
    //     {
    //         delete itr->second;
    //         faculties.erase(itr);
    //     }
    // }

    void City::addEmployee(const int id, const string first_name, const string last_name, const int birth_year)
    {
        Employee employee_to_add(id, first_name, last_name, birth_year);
        if(employees.find(id) != employees.end()){
            throw mtm::EmployeeAlreadyExists();
        }
        employees.insert({id, employee_to_add});
        Employee* ptr_to_employee = &((*(employees.find(id))).second);
        citizens.insert({id, ptr_to_employee});
    }
    
    void City::addManager(const int id, const string first_name, const string last_name, const int birth_year)
    {
        Manager manager_to_add(id, first_name, last_name, birth_year);
        if(managers.find(id) != managers.end()){
            throw mtm::ManagerAlreadyExists();
        }
        managers.insert({id, manager_to_add});
        Manager* ptr_to_manager = &((*(managers.find(id))).second);
        citizens.insert({id, ptr_to_manager});
    }

    void City::createWorkPlace(const int id, const string name, 
                        const unsigned int workers_salary,const unsigned int managers_salary)
    {
        WorkPlace workplace_to_add(id, name, workers_salary, managers_salary);
        try{
            work_places.at(id);
        }
        catch(std::out_of_range& e){
            work_places.insert({id, workplace_to_add});
            return;
        }
        throw mtm::WorkplaceAlreadyExists();
    }

    void City::teachAtFaculty(const int employee_id, const int faculty_id)
    {
        try{
            citizens.at(employee_id);
        }
        catch(std::out_of_range& e){
            throw mtm::EmployeeDoesNotExist();
        }
        try{
            faculties.at(faculty_id);
        }
        catch(std::out_of_range& e){
            throw mtm::FacultyDoesNotExist();
        }
        (faculties.at(faculty_id)).teach(&(employees.at(employee_id)));
    }
    
    void City::hireManagerAtWorkplace(const int manager_id, const int workplace_id)
    {
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
        (work_places.at(workplace_id)).hireManager(&(managers.at(manager_id)));
    }

    void City::fireEmployeeAtWorkplace(const int employee_id, const int manager_id, const int workplace_id)
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
        (work_places.at(workplace_id)).fireEmployee(employee_id, manager_id);
    }

    void City::fireManagerAtWorkplace(const int manager_id, const int workplace_id)
    {
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
        (work_places.at(workplace_id)).fireManager(manager_id);
    }

    int City::findWorkPlaceOfEmployee(const int employee_id)
    {
        for(const pair<const int, Manager> manager : managers){
            if(manager.second.isEmployeeEmployed(employee_id)){
                for (const pair<const int, WorkPlace> work_place : work_places){
                    if((work_place.second).isManagerInWorkplace(manager.second.getId())){
                        return (work_place.second).getID();
                    }
                }      
            }
        }
        return UNEMPLOYED;
    }

    bool City::isWorkingInTheSameWorkplace(const int employee1_id, const int employee2_id)
    {
        try{
            citizens.at(employee1_id);
            citizens.at(employee2_id);
        }
        catch(std::out_of_range& e){
            throw mtm::EmployeeDoesNotExist();
        }
        int employee1_workplace_id = this->findWorkPlaceOfEmployee(employee1_id);
        int employee2_workplace_id = this->findWorkPlaceOfEmployee(employee2_id);
        return (employee1_workplace_id == employee2_workplace_id && employee1_workplace_id != UNEMPLOYED);
    }
    
    int City::printAllAboveSalary(std::ostream& os, const int salary) const
    {
        int citizens_above_salary = 0;
        for(const pair<const int, Citizen*> citizen : citizens)
        {
            if((citizen.second)->getSalary() >= salary){
                citizens_above_salary++;
                (citizen.second)->printShort(os);
            }
        }
        return citizens_above_salary;
    }

    void City::printAllEmployeesWithSkill(std::ostream& os, const int skill_id)
    {
        for(const pair<const int, Employee> employee : employees){
            if(employee.second.hasSkill(skill_id)){
                employee.second.printShort(os);
            }
        }
    } 
}