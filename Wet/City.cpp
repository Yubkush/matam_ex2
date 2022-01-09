#include "City.h"
#include "exceptions.h"

#define UNEMPLOYED -1

using mtm::City;

namespace mtm
{
    City::City(const string name): name(name), citizens(), employees(), managers(), work_places(), faculties()
    {

    }

    void City::resetCity()
    {
        for(pair<const int, Employee> employee : this->employees){
            employee.second.setSalary(-employee.second.getSalary());
            (this->citizens).insert({employee.second.getId(), &((this->employees).at(employee.second.getId()))});
        }
        for(pair<const int, Manager> manager : managers){
            manager.second.setSalary(-manager.second.getSalary());
            manager.second.emptyEmployeeGroup();
            (this->citizens).insert({manager.second.getId(), &((this->managers).at(manager.second.getId()))});
        }
        for(pair<const int, Workplace> work_place : this->work_places){
            work_place.second.emptyWorkPlace();
        }
    }

    void City::copyHiring(const City& city)
    {
        for(pair<const int, Manager> manager : this->managers){
            for(pair<const int, Workplace> work_place : city.work_places){
                if(work_place.second.isManagerInWorkplace(manager.second.getId())){
                    ((this->work_places).at(work_place.second.getId())).
                            hireManager(&((this->managers).at(manager.second.getId())));
                    break;
                }
            }
        }
        for(pair<const int, Employee> employee : this->employees){
            for(pair<const int, Workplace> work_place : city.work_places){
                try{
                    const int manager_id = work_place.second.getManagerIdOfEmployee(employee.second.getId());
                    ((this->work_places).at(work_place.second.getId())).
                            hireEmployeeWithoutCondition(&((this->employees).at(employee.second.getId())), manager_id);
                }
                catch(mtm::EmployeeIsNotHired& e){
                    continue;
                }
            }
        }
    }

    void City::copyCity(const City& city)
    {
        this->name = city.name;
        this->citizens;
        this->employees = city.employees;
        this->managers = city.managers;
        this->work_places = city.work_places;
        this->faculties = city.faculties;
        /* Reset all employees, managers, workplaces */
        this->resetCity();
        /* Hire according to hierarchy in the original city */
        this->copyHiring(city);
    }

    City::City(const City& city)
    {
        copyCity(city);
    }

    City& City::operator=(const City& city)
    {
        copyCity(city);
        return *this;
    }

    void City::addEmployee(const int id, const string first_name, const string last_name, const int birth_year)
    {
        Employee employee_to_add(id, first_name, last_name, birth_year);
        if(citizens.find(id) != citizens.end()){
            throw mtm::CitizenAlreadyExists();
        }
        employees.insert({id, employee_to_add});
        Employee* ptr_to_employee = &((*(employees.find(id))).second);
        citizens.insert({id, ptr_to_employee});
    }
    
    void City::addManager(const int id, const string first_name, const string last_name, const int birth_year)
    {
        Manager manager_to_add(id, first_name, last_name, birth_year);
        if(citizens.find(id) != citizens.end()){
            throw mtm::CitizenAlreadyExists();
        }
        managers.insert({id, manager_to_add});
        Manager* ptr_to_manager = &((*(managers.find(id))).second);
        citizens.insert({id, ptr_to_manager});
    }

    void City::addFaculty(const int id, const Skill skill, const unsigned int add_points, 
                    Condition *admission_condition)
    {
        try{
            faculties.at(id);
        }
        catch(std::out_of_range& e){
            Faculty<Condition> faculty_to_add(id, skill, add_points, admission_condition);
            faculties.insert({id, faculty_to_add});
            return;
        }
        throw mtm::FacultyAlreadyExists();
    }

    void City::createWorkplace(const int id, const string name, 
                        const unsigned int workers_salary,const unsigned int managers_salary)
    {
        Workplace Workplace_to_add(id, name, workers_salary, managers_salary);
        try{
            work_places.at(id);
        }
        catch(std::out_of_range& e){
            work_places.insert({id, Workplace_to_add});
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
    
    void City::hireManagerAtWorkplace(const int manager_id, const int Workplace_id)
    {
        try{
            managers.at(manager_id);
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
        (work_places.at(Workplace_id)).hireManager(&(managers.at(manager_id)));
    }

    void City::fireEmployeeAtWorkplace(const int employee_id, const int manager_id, const int Workplace_id)
    {
        try{
            employees.at(employee_id);
        }
        catch(std::out_of_range& e){
            throw mtm::EmployeeDoesNotExist();
        }
        try{
            managers.at(manager_id);
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
        (work_places.at(Workplace_id)).fireEmployee(employee_id, manager_id);
    }

    void City::fireManagerAtWorkplace(const int manager_id, const int Workplace_id)
    {
        try{
            managers.at(manager_id);
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
        (work_places.at(Workplace_id)).fireManager(manager_id);
    }

    int City::findWorkplaceOfEmployee(const int employee_id)
    {
        for(const pair<const int, Manager> manager : managers){
            if(manager.second.isEmployeeEmployed(employee_id)){
                for (const pair<const int, Workplace> work_place : work_places){
                    if((work_place.second).isManagerInWorkplace(manager.second.getId())){
                        return (work_place.second).getId();
                    }
                }      
            }
        }
        return UNEMPLOYED;
    }

    bool City::isWorkingInTheSameWorkplace(const int employee1_id, const int employee2_id)
    {
        try{
            employees.at(employee1_id);
            employees.at(employee2_id);
        }
        catch(std::out_of_range& e){
            throw mtm::EmployeeDoesNotExist();
        }
        int employee1_Workplace_id = this->findWorkplaceOfEmployee(employee1_id);
        int employee2_Workplace_id = this->findWorkplaceOfEmployee(employee2_id);
        return (employee1_Workplace_id == employee2_Workplace_id && employee1_Workplace_id != UNEMPLOYED);
    }
    
    int City::getAllAboveSalary(std::ostream& os, const int salary) const
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