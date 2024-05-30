// fault.h
#pragma once
#ifndef FAULT_H
#define FAULT_H

#include "ship.hpp"
//#include "person.hpp"
#include <string>

using namespace std;


enum FaultLevel
{
    SLIGHT,
    MEDIUM,
    SEVERE,
};

enum FaultType
{
    OIL_PRESSURE,
    WATER_LEVEL,
    TEMPERATURE,
    // ... diğer hata tipleri
};


class Fault
{

friend void fixFault(Fault *faults, int faultId, const string& fixDate, const string& fixDescription);

public:
    Fault(int faultId, int shipId, int controllerId, FaultType faultType, FaultLevel faultLevel,
          string date, string faultDescription, string fixedDate,
          string fixDescription, int engineerId);

    // Getter ve setter fonksiyonları
    int getFaultID() const;
    void setFaultID(int id);

    int getShipID() const;
    void setShipID(int id);

    int getControllerID() const;
    void setControllerID(int id);

    string &getFaultDescription();
    void setFaultDescription(const string &description);

    FaultType getFaultType() const;
    void setFaultType(FaultType t);

    FaultLevel getFaultLevel() const;
    void setFaultLevel(FaultLevel l);

    bool getIsRepaired() const;
    void setIsRepaired(bool repaired);

    bool getIsThereProblem() const;
    void setIsThereProblem(bool problem);

    string &getDate();
    void setDate(const string &date);

    string &getFixedDate();
    void setFixedDate(const string &fixedDate);

    string &getFixDescription();
    void setFixDescription(const string &fixDescription);

    int getEngineerID() const;
    void setEngineerID(int id);


    // Diğer fonksiyonlar
   
    static void listRepairedProblems(Fault *faults, int faultCount);
    static void listUnrepairedProblems(Fault *faults, int faultCount);
    static void addFault(Fault *faults, int &faultCount, int shipId, int controllerId, FaultType faultType, FaultLevel faultLevel, const string &date, const string &faultDescription, int engineerId);
    static void assignEngineerToFault(Fault *faults, int faultID, int engineerID);
    static void listAssignedFaults(Fault *faults, int faultCount, int engineerId);
    //static void fixFault(Fault *faults, int faultId, const string& fixDate, const string& fixDescription);

private:
    int faultID;
    string faultDescription;
    FaultType faultType;
    FaultLevel faultLevel;
    bool isRepaired;
    bool isThereProblem;
    int shipID;
    int controllerID;
    string date;
    string fixedDate;
    string fixDescription;
    int engineerID;
    //Person *duzeltmeGorevlisi;
};

#endif // FAULT_H
