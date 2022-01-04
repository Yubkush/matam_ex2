#ifndef SKILL_H_
#define SKILL_H_

#include <string>
#include <iostream>

using std::string;
using std::ostream;

namespace mtm
{
    /**
     * Skill class declaration
     */
    class Skill 
    {
        private:
            const int id;
            const string name;
            int required_points;
        
        public:
            //c'tor
            Skill(const int id, const string name, int required_points);
            //d'tor
            ~Skill() = default;
            //copy c'tor
            Skill(const Skill& skill) = default;
            
            //getters
            /**
             * @brief Get the Id object
             * 
             * @return int
             */
            int getId() const;
            /**
             * @brief Get the Name object
             * 
             * @return string
             */
            string getName() const;
            /**
             * @brief Get the Required Points object
             * 
             * @return int Required Points
             */
            int getRequiredPoints() const;

            //overloaded operators
            /**
             * @brief increment required points by one
             * 
             * @return Skill 
             */
            Skill operator++(int);
            /**
             * @brief increment required points by add
             * 
             * @param add added to skill required points
             * @return Skill& 
             */
            Skill& operator+=(int add);
            /**
             * @brief print a skill
             * 
             * @param os output stream which we print to 
             * @param skill to print
             * @return ostream& 
             */
            friend ostream& operator<<(ostream& os, const Skill& skill);
    };

    /**
     * @brief compare skills id by =
     * 
     * @return true if equal
     * @return false if not equal
     */
    bool operator==(const Skill& skill_1, const Skill& skill_2);
    /**
     * @brief compare skills id by <
     * 
     * @return true skill_1 id is less than skill_2 id
     * @return false otherwise
     */
    bool operator<(const Skill& skill_1, const Skill& skill_2);
    /**
     * @brief compare skills id by >
     * 
     * @return true skill_1 id is bigger than skill_2 id
     * @return false otherwise
     */
    bool operator>(const Skill& skill_1, const Skill& skill_2);
    /**
     * @brief compare skills id by <=
     * 
     * @return true skill_1 id is smaller than skill_2 id or equal
     * @return false skill_1 id is bigger than skill_2 id
     */
    bool operator<=(const Skill& skill_1, const Skill& skill_2);
    /**
     * @brief compare skills id by >=
     * 
     * @return true skill_1 id is bigger than skill_2 id or equal
     * @return false skill_1 id is smaller than skill_2 id
     */
    bool operator>=(const Skill& skill_1, const Skill& skill_2);
    /**
     * @brief compare skills id by !=
     * 
     * @return true if not equal
     * @return false if equal
     */
    bool operator!=(const Skill& skill_1, const Skill& skill_2);
    /**
     * @brief increment required points by add
     * 
     * @param skill to change
     * @param add added to skill required points
     * @return Skill
     */
    Skill operator+(const Skill& skill ,int add);
    /**
     * @brief increment required points by add
     * 
     * @param skill to change
     * @param add added to skill required points
     * @return Skill
     */
    Skill operator+(int add, const Skill& skill);
}

#endif /* SKILL_H_ */


