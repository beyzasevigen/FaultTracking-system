// person.h
#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "ship.hpp"
#include "fault.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {

  
public:

    Person();
    virtual ~Person();
    
    Person(int id, const string& name, const string& user, const string& pass);

    // Getter ve Setter fonksiyonları
    int getPersonID() const;
    void setPersonID(int id);

    const string& getPersonName() const;
    void setPersonName(const string& name);

    const string& getUsername() const;
    void setUsername(const string& user);

    const string& getPassword() const;
    void setPassword(const string& pass);


    // Diğer fonksiyonlar

private:
    int personID;
    string personName;
    string username;
    string password;

    
};


#endif // PERSON_H
