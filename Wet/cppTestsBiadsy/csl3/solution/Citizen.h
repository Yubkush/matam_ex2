#ifndef CITIZEN_H_
#define CITIZEN_H_

#include <string>
#include <iostream>

using std::string;

namespace mtm
{
    /**
     * Citizen class declaration
     */
    class Citizen{
        private:
            const int id;
            const string first_name;
            const string last_name;
            const int birth_year;
        
        public:
            //c'tor
            Citizen(const int id, const string first_name, const string last_name, const int birth_year);
            //d'tor
            virtual ~Citizen() = default;
            //copy c'tor
            Citizen(const Citizen& citizen) = default;

            //getters
            /**
             * @brief Get the Id object
             * 
             * @return int 
             */
            int getId() const;
            /**
             * @brief Get the First Name object
             * 
             * @return string 
             */
            string getFirstName() const;
            /**
             * @brief Get the Last Name object
             * 
             * @return string 
             */
            string getLastName() const;
            /**
             * @brief Get the Birth Year object
             * 
             * @return int 
             */
            int getBirthYear() const;
            /**
             * @brief Get the Salary object
             * 
             * @return int 
             */
            virtual int getSalary() const = 0;

            //virtual functions
            virtual std::ostream& printShort(std::ostream& os) const = 0;
            virtual std::ostream& printLong(std::ostream& os) const = 0;
            virtual Citizen* clone() const = 0;
    };

    //overloaded operators
    /**
     * @brief compare citizens id by =
     * 
     * @return true if equal
     * @return false if not equal
     */
    bool operator==(const Citizen& citizen_1, const Citizen& citizen_2);
    /**
     * @brief compare citizens id by >
     * 
     * @return true citizen_1 id is bigger than citizen_2 id
     * @return false otherwise
     */
    bool operator>(const Citizen& citizen_1, const Citizen& citizen_2);
    /**
     * @brief compare citizens id by <
     * 
     * @return true citizen_1 id is less than citizen_2 id
     * @return false otherwise
     */
    bool operator<(const Citizen& citizen_1, const Citizen& citizen_2);
    /**
     * @brief compare citizens id by <=
     * 
     * @return true citizen_1 id is smaller than citizen_2 id or equal
     * @return false citizen_1 id is bigger than citizen_2 id
     */
    bool operator<=(const Citizen& citizen_1, const Citizen& citizen_2);
    /**
     * @brief compare citizens id by >=
     * 
     * @return true citizen_1 id is bigger than citizen_2 id or equal
     * @return false citizen_1 id is smaller than citizen_2 id
     */
    bool operator>=(const Citizen& citizen_1, const Citizen& citizen_2);
    /**
     * @brief compare citizens id by !=
     * 
     * @return true if not equal
     * @return false if equal
     */
    bool operator!=(const Citizen& citizen_1, const Citizen& citizen_2);   
}

#endif /* CITIZEN_H_ */