#ifndef CITIZEN_H_
#define CITIZEN_H_

#include <string>
#include <iostream>

using std::string;

namespace mtm
{
    class Citizen{
        private:
            const int id;
            const string first_name;
            const string last_name;
            const int birth_year;
        
        public:
            //c'tors and d'tor
            Citizen(const int id, const string first_name, const string last_name, const int birth_year);
            virtual ~Citizen() = default;
            Citizen(const Citizen& citizen) = default;

            //getters
            int getId() const;
            string getFirstName() const;
            string getLastName() const;
            int getBirthYear() const;

            //virtual functions
            virtual std::ostream& printShort(std::ostream& os) const = 0;
            virtual std::ostream& printLong(std::ostream& os) const = 0;
            virtual Citizen* clone() const = 0;
    };

    //overloaded operators
    bool operator==(const Citizen& citizen_1, const Citizen& citizen_2);
    bool operator>(const Citizen& citizen_1, const Citizen& citizen_2);
    bool operator<(const Citizen& citizen_1, const Citizen& citizen_2);
    bool operator<=(const Citizen& citizen_1, const Citizen& citizen_2);
    bool operator>=(const Citizen& citizen_1, const Citizen& citizen_2);
    bool operator!=(const Citizen& citizen_1, const Citizen& citizen_2);   
}

#endif /* CITIZEN_H_ */