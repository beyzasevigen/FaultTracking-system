// person.cpp
#include "../header/person.hpp"
#include "../header/database.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Person::Person() : personID(0), personName(""), username(""), password("") {}

Person::~Person() {}

Person::Person(int id, const string& name, const string& user, const string& pass)
    : personID(id), personName(name), username(user), password(pass) {
        Database::people.push_back(this);
}

int Person::getPersonID() const {
    return personID;
}

void Person::setPersonID(int id) {
    personID = id;
}

const string& Person::getPersonName() const {
    return personName;
}

void Person::setPersonName(const string& name) {
    personName = name;
}

const string& Person::getUsername() const {
    return username;
}

void Person::setUsername(const string& user) {
    username = user;
}

const string& Person::getPassword() const {
    return password;
}

void Person::setPassword(const string& pass) {
    password = pass;
}


