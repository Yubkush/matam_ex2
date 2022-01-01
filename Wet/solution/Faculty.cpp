#include "Faculty.h"

// using mtm::Faculty;
// using mtm::Skill;

// namespace mtm
// {   
//     template <class Condition_T>
//     Faculty<Condition_T>::Faculty(const int id, const Skill skill,
//                         const unsigned int add_points, Condition *admission_condition):
//                     id(id), skill(skill), add_points(add_points), admission_condition(admission_condition)
//     {
        
//     }

//     template <class Condition_T>
//     int Faculty<Condition_T>::getId() const
//     {
//         return id;
//     }

//     template <class Condition_T>
//     Skill Faculty<Condition_T>::getSkill() const
//     {
//         return skill;
//     }

//     template <class Condition_T>
//     int Faculty<Condition_T>::getAddedPoints() const
//     {
//         return add_points;
//     }

//     template <class Condition_T>      
//     void Faculty<Condition_T>::teach(Employee* employee)
//     {
//         if(!((*admission_condition)(employee))){
//             throw mtm::EmployeeNotAccepted();
//         }
//         employee->learnSkill(skill);
//         employee->setScore(add_points);
//     }
// }