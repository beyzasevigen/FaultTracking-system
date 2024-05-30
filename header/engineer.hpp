#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Engineer : public Person {
public:
    Engineer(int id, const string& name, const string& user, const string& pass);

    Engineer();
    virtual ~Engineer() override {}
    
    float operator/(const Fault* faultArray) const;
};


#endif 
