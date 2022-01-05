#include <iostream>
#include "../Workplace.h"
#include <cassert>

using namespace mtm;
using std::cout;
using std::endl;

class Condition{
    public:
    bool operator()(Employee* emp){
        return emp->getId()>0;
    }
};

class Condition_level{
    public:
    bool operator()(Employee* emp){
        return emp->getScore()>5;
    }
};
    
int main() {
    Workplace Meta(1,"Meta", 10000, 20000);
    Workplace Amazon(2, "Amazon", 5000, 9000);
    Employee* e1 = new Employee(1, "John", "Williams", 2002);
    Employee* e2 = new Employee(2, "Alex", "Martinez", 2000);
    Employee* e3 = new Employee(3, "Bruce", "Wayne", 1972);
    Manager* m1 = new Manager(1,"Robert", "stark", 1980);
    Manager* m2 = new Manager(3,"JJ", "K", 1976);
    Meta.hireManager(m1);
    Condition condition;
    Condition_level condition_level;
    Meta.hireEmployee(condition,e1,m1->getId());
    try
    {
        Meta.hireEmployee(condition,e1,m1->getId());
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::EmployeeAlreadyHired).name());
    }
    try
    {
        Meta.hireEmployee(condition,e1,2);
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::ManagerIsNotHired).name());
    }
    try
    {
        Meta.hireEmployee(condition_level,e3,m1->getId());
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::EmployeeNotSelected).name());
    }
    Meta.hireEmployee(condition,e2,m1->getId());
    try
    {
        Amazon.hireManager(m1);
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::CanNotHireManager).name());
    }
    try
    {
        Meta.hireManager(m1);
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::ManagerAlreadyHired).name());
    }
    Meta.hireEmployee(condition, e3, m1->getId());
    Meta.fireEmployee(e3->getId(), m1->getId());
    try
    {
        Meta.fireEmployee(e3->getId(), m1->getId());
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::EmployeeIsNotHired).name());
    }
    try
    {
        Meta.fireEmployee(e2->getId(),2);
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::ManagerIsNotHired).name());
    }
    cout << Meta;
    Meta.fireManager(m1->getId());
    try
    {
        Meta.fireManager(m1->getId());
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::ManagerIsNotHired).name());
    }
    cout << Meta;
    Amazon.hireManager(m1);
    Amazon.hireManager(m2);
    Amazon.hireEmployee(condition,e1,m1->getId());
    Amazon.hireEmployee(condition,e2,m1->getId());
    Amazon.hireEmployee(condition, e3, m2->getId());
    cout << Amazon;
    Amazon.fireManager(m1->getId());
    cout << Amazon;
    delete e1;
    delete e2;
    delete e3;
    delete m1;
    delete m2;
    return 0;
}