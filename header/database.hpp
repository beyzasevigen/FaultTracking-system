// database.hpp
#pragma once
#include "Person.hpp"

template <typename Base, typename Derived>
static bool instanceof (const Derived *ptr)
{
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

class Database
{
public:
    //static const int MAX_PEOPLE = 100;
    static const int MAX_FAULTS = 100;
    Database();

    static int insertPerson(const Person &person);
    static int readPerson();
    static int deletePersonFromFile(int personID);
    static void calculateAndPrintSolvedFaultRate(const vector<Person*>& people, Fault* faultList, int engineerId);
    static Person *login(string username, string password);
    static void findPerson(int personID);
    static vector<Person*> people;
    static int userCount;

private:
   // vector<Person> people;
   // int userCount;
};
