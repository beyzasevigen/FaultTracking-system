#include "../header/fault.hpp"
#include "../header/database.hpp"
#include <iostream>

using namespace std;

//int MAX_FAULTS;
int faultCount;


void Fault::addFault(Fault *faults, int &faultCount, int shipId, int controllerId, FaultType faultType, FaultLevel faultLevel, const string &date, const string &faultDescription, int engineerId) {
    if (faultCount < Database::MAX_FAULTS) {
        // Yeni bir Fault nesnesi oluştur
        Fault newFault(faultCount + 1, shipId, controllerId, faultType, faultLevel, date, faultDescription, "", "", 0);

        newFault.setIsRepaired(false);
        newFault.setIsThereProblem(true);

        // faults dizisine yeni Fault nesnesini ekle
        faults[faultCount] = newFault;

        // faultCount'u artır
        faultCount++;

        cout << "Fault added successfully.\n";
    } else {
        cout << "Error: Maximum fault count reached. Cannot add more faults.\n";
    }
}

void fixFault(Fault *faults, int faultId, const string& fixDate, const string& fixDescription) {
    for (int i = 0; i < Database::MAX_FAULTS; ++i) {
        if (faults[i].getFaultID() == faultId) {
            
            cout << "Fault with ID " << faultId << " has been fixed." << endl;
            cout << "Fix Date: " << fixDate << endl;
            cout << "Fix Description: " << fixDescription << endl;

            // Hatanın durumunu güncelle
            faults[i].isRepaired = true;
            faults[i].isThereProblem = false;

            // fixDate ve fixDescription'u ayarla
            faults[i].fixedDate = fixDate;
            faults[i].fixDescription = fixDescription;

            return; // Hata bulundu, işlem tamamlandı.
        }
    }
    // Eğer belirtilen ID'ye sahip hata bulunamadıysa:
    cout << "Fault with ID " << faultId << " not found." << endl;
}

void Fault::assignEngineerToFault(Fault *faults, int faultID, int engineerID) {
    for (int i = 0; i < Database::MAX_FAULTS; ++i) {
        if (faults[i].getFaultID() == faultID) {
            faults[i].setEngineerID(engineerID);
            return; // Hata bulundu, işlem tamamlandı.
        }
    }

    // Eğer bu noktaya ulaşıldıysa, hata bulunamadı.
    cout << "Error: Fault with ID " << faultID << " not found." << endl;
}

void listAssignedFaults(Fault *faults, int faultCount, int engineerId) {
        cout << "Assigned Faults for Engineer ID " << engineerId << ":" << endl;

        for (int i = 0; i < faultCount; ++i) {
            if (faults[i].getEngineerID() == engineerId) {
                cout << "Fault ID: " << faults[i].getFaultID() << endl;
                cout << "Engineer ID: " << faults[i].getEngineerID() << endl;
                
                cout << "-------------------------" << endl;
            }
        }
    }

void Fault::listUnrepairedProblems(Fault *faults, int faultCount)
{
    cout << "Unrepaired faults:" << endl;
    for (int i = 0; i < faultCount; ++i)
    {
        if (faults[i].getIsThereProblem() && !faults[i].getIsRepaired())
        {
            cout << "Error ID: " << faults[i].getFaultID() << ", Type: " << faults[i].getFaultType() << ", Level: " << faults[i].getFaultLevel() << endl;
        }
    }
}

void Fault::listRepairedProblems(Fault *faults, int faultCount)
{
    cout << "Repaired faults:" << endl;
    for (int i = 0; i < faultCount; ++i)
    {
        if (faults[i].getIsThereProblem() && faults[i].getIsRepaired())
        {
            cout << "Error ID: " << faults[i].getFaultID() << ", Type: " << faults[i].getFaultType() << ", Level: " << faults[i].getFaultLevel() << endl;
        }
    }
}


Fault::Fault(int faultId, int shipId, int controllerId, FaultType faultType, FaultLevel faultLevel,
             string date, string faultDescription, string fixedDate,
             string fixDescription, int engineerId)
    : faultID(faultId), shipID(shipId), controllerID(controllerId), faultType(faultType),
      faultLevel(faultLevel), date(date), faultDescription(faultDescription),
      fixedDate(fixedDate), fixDescription(fixDescription), engineerID(engineerId)
{}

int Fault::getFaultID() const
{
    return faultID;
}

void Fault::setFaultID(int id)
{
    faultID = id;
}

int Fault::getShipID() const
{
    return shipID;
}

void Fault::setShipID(int id)
{
    shipID = id;
}

int Fault::getControllerID() const
{
    return controllerID;
}

void Fault::setControllerID(int id)
{
    controllerID = id;
}

string &Fault::getFaultDescription()
{
    return faultDescription;
}

void Fault::setFaultDescription(const string &description)
{
    faultDescription = description;
}

FaultType Fault::getFaultType() const
{
    return faultType;
}

void Fault::setFaultType(FaultType faultType)
{
    faultType = faultType;
}

FaultLevel Fault::getFaultLevel() const
{
    return faultLevel;
}

void Fault::setFaultLevel(FaultLevel l)
{
    faultLevel = l;
}

bool Fault::getIsRepaired() const
{
    return isRepaired;
}

void Fault::setIsRepaired(bool repaired)
{
    isRepaired = repaired;
}

bool Fault::getIsThereProblem() const
{
    return isThereProblem;
}

void Fault::setIsThereProblem(bool problem)
{
    isThereProblem = problem;
}

string &Fault::getDate()
{
    return date;
}

void Fault::setDate(const string &date)
{
    this->date = date;
}

string &Fault::getFixedDate()
{
    return fixedDate;
}

void Fault::setFixedDate(const string &fixedDate)
{
    this->fixedDate = fixedDate;
}

string &Fault::getFixDescription()
{
    return fixDescription;
}

void Fault::setFixDescription(const string &fixDescription)
{
    this->fixDescription = fixDescription;
}

int Fault::getEngineerID() const
{
    return engineerID;
}

void Fault::setEngineerID(int id)
{
    engineerID = id;
}

/*void fixFault(Fault *faults, int faultId, const string& fixDate, const string& fixDescription) {
        for (int i = 0; i < Database::MAX_FAULTS; ++i) {
            if (faults[i].getFaultID() == faultId) {
                
                cout << "Fault with ID " << faultId << " has been fixed." << endl;
                cout << "Fix Date: " << fixDate << endl;
                cout << "Fix Description: " << fixDescription << endl;

                // Hatanın durumunu güncelle
                faults[i].setIsRepaired(true);
                faults[i].setIsThereProblem(false);

                // fixDate ve fixDescription'u ayarla
                faults[i].setFixedDate(fixDate);
                faults[i].setFixDescription(fixDescription);

                return; // Hata bulundu, işlem tamamlandı.
            }
        }
        // Eğer belirtilen ID'ye sahip hata bulunamadıysa:
        cout << "Fault with ID " << faultId << " not found." << endl;
    }*/
