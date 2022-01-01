# The first line states the minimum CMake version to use with this project
# and is requires by CMake.
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 11)

# Set <PROJNAME> to be your project name. We set CXX (C++) here as the target language.
project(dry VERSION 0.1.0 LANGUAGES CXX)

# If you want to see "under the hood" of CMake, uncomment this:
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Define variables containing compiler flags for gcc
set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# Set the flags for gcc
set(CMAKE_CPP_FLAGS ${MTM_FLAGS_DEBUG})


# Add the names of your source files here
set(SKILL_CPP_FILES Skill.cpp)
set(EMPLOYEE_CPP_FILES Citizen.cpp Employee.cpp)
set(MANAGER_CPP_FILES Manager.cpp)
set(WORKPLACE_CPP_FILES WorkPlace.cpp)
set(FACULTY_CPP_FILES Faculty.cpp )
set(CITY_CPP_FILES City.cpp city_test.cpp)

add_executable(faculty ${SKILL_CPP_FILES} ${EMPLOYEE_CPP_FILES} ${MANAGER_CPP_FILES} ${WORKPLACE_CPP_FILES} ${FACULTY_CPP_FILES} ${CITY_CPP_FILES} exceptions.cpp)