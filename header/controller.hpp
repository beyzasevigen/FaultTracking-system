#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "person.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Controller : public Person {
public:
    Controller(int id, const string& name, const string& user, const string& pass);

    Controller();
    virtual ~Controller() override {}

};


#endif 
