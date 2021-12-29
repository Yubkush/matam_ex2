#include <iostream>
#include "../WorkPlace.h"
#include "../Faculty.h"
#include <cassert>

using namespace mtm;
using std::cout;
using std::endl;

bool facultyCond(Employee* emp){
    return emp->getId()>1;
}

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
    Skill s1(1, "C++", 5);
    Skill s2(2, "C", 5);
    Faculty CS(1, facultyCond, s1, 10);
    WorkPlace Meta(1,"Meta", 10000, 20000);
    Employee* e1 = new Employee(1, "John", "Williams", 2002);
    Employee* e2 = new Employee(2, "Alex", "Martinez", 2000);
    Employee* e3 = new Employee(3, "Bruce", "Wayne", 1972);
    Manager* m1 = new Manager(1,"Robert", "stark", 1980);
    Manager* m2 = new Manager(3,"JJ", "K", 1976);
    try
    {
        CS.teach(e2);
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::CanNotLearnSkill).name());
    }
    try{
        CS.teach(e1);
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::EmployeeNotAccepted).name());
    }
    e2->printLong(cout);
    e2->setScore(9);
    CS.teach(e2);
    try
    {
        CS.teach(e2);
    }
    catch(const mtm::Exception& e)
    {
        assert(typeid(e).name() == typeid(mtm::SkillAlreadyLearned).name());
    }
    e2->printLong(cout);
    Meta.hireManager(m1);
    Condition condition;
    Condition_level condition_level;
    Meta.hireEmployee(condition, e2, m1->getId());
    Meta.hireEmployee(condition,e1,m1->getId());
    cout << Meta;
    Meta.fireManager(m1->getId());
    cout << Meta;
    delete e1;
    delete e2;
    delete e3;
    delete m1;
    delete m2;
    return 0;
}