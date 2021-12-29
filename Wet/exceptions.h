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

}

#endif /* EXCEPTIONS_H_ */