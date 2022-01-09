#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
#include <string>

using std::string;
using std::exception;

namespace mtm
{
    class Exception : public exception
    {
        public:
            Exception() = default;
            virtual ~Exception() = default;
    };

    class NegativePoints : public Exception 
    {
        public:
            explicit NegativePoints() = default;
    };

    class SkillAlreadyLearned : public Exception 
    {
        public:
            explicit SkillAlreadyLearned() = default;
    };
    class CanNotLearnSkill : public Exception 
    {
        public:
            explicit CanNotLearnSkill() = default;
    };
    class DidNotLearnSkill : public Exception 
    {
        public:
            explicit DidNotLearnSkill() = default;
    };

    class EmployeeAlreadyHired : public Exception
    {
        public:
            explicit EmployeeAlreadyHired() = default;
    };
    class EmployeeIsNotHired : public Exception
    {
        public:
            explicit EmployeeIsNotHired() = default;
    };

    class EmployeeNotSelected : public Exception
    {
        public:
            explicit EmployeeNotSelected() = default;
    };
    class ManagerIsNotHired : public Exception
    {
        public:
            explicit ManagerIsNotHired() = default;
    };
    class ManagerAlreadyHired : public Exception
    {
        public:
            explicit ManagerAlreadyHired() = default;
    };
    class CanNotHireManager : public Exception
    {
        public:
            explicit CanNotHireManager() = default;
    };
    class EmployeeNotAccepted : public Exception
    {
        public:
            explicit EmployeeNotAccepted() = default;
    };

    class CitizenAlreadyExists: public Exception
    {
        public:
            explicit CitizenAlreadyExists() = default;
    };
    class FacultyAlreadyExists: public Exception
    {
        public:
            explicit FacultyAlreadyExists() = default;
    };
    class WorkplaceAlreadyExists: public Exception
    {
        public:
            explicit WorkplaceAlreadyExists() = default;
    };
    class EmployeeDoesNotExist: public Exception
    {
        public:
            explicit EmployeeDoesNotExist() = default;
    };
    class ManagerDoesNotExist: public Exception
    {
        public:
            explicit ManagerDoesNotExist() = default;
    };
    class FacultyDoesNotExist: public Exception
    {
        public:
            explicit FacultyDoesNotExist() = default;
    };
    class WorkplaceDoesNotExist: public Exception
    {
        public:
            explicit WorkplaceDoesNotExist() = default;
    };
    
}

#endif /* EXCEPTIONS_H_ */