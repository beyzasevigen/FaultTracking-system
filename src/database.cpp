// database.cpp
#include "../header/database.hpp"
#include "../header/person.hpp"
#include "../header/engineer.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Database::Database() {}
int Database::userCount = 0;
vector<Person*> Database::people;
int Database::insertPerson(const Person &person)
{
    
    ofstream file("people.txt", ios::app);
    if (!file)
    {
        cerr << "Error while opening the file!" << endl;
        return 1;
    }

    file << person.getPersonID() << " "
         << person.getPersonName() << " "
         << person.getUsername() << " "
         << person.getPassword() << endl;

    userCount++;     

    file.close();

    return 0;
}

int Database::readPerson()
{
    ifstream file("people.txt");
    if (!file)
    {
        cerr << "Error while opening the file!" << endl;
        return 1;
    }

    people.clear(); // Önceki verileri temizle

    Person* currentPerson;
    int found = 0;
    int personID;
    string personName;
    string username;
    string password;

    while (file >> personID >> personName >> username >> password)
    {
        currentPerson = new Person(personID, personName, username, password);
        people.push_back(currentPerson);
    }

    file.close();

    return 0;
}

int Database::deletePersonFromFile(int personID)
{
    ifstream inputFile("people.txt");
    ofstream outputFile("temp_people.txt");

    if (!inputFile || !outputFile)
    {
        cerr << "Error while opening the file!" << endl;
        return 1;
    }

    Person* currentPerson;
    int found = 0;
    int pId;
    string personName;
    string username;
    string password;

    while (inputFile >> pId >> personName >> username >> password)
    {
        currentPerson = new Person(pId, personName, username, password);
        if (currentPerson->getPersonID() == personID)
        {
            found = 1;
        }
        else
        {
            outputFile << currentPerson;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("people.txt");
    rename("temp_people.txt", "people.txt");

    if (found)
    {
        readPerson();
    }

    return 0;
}

void Database::findPerson(int personID) {
    ifstream file("person.txt");

    if (!file.is_open()) {
        cout << "Error while opening the file!" << endl;
        return;
    }

    Person person;
    bool personFound = false;

    int found = 0;
    int pId;
    string personName;
    string username;
    string password;

    while (file >> pId >> personName >> username >> password)
    {
        if (personID == person.getPersonID()) {
            cout << "\nPerson found! Name: " << person.getPersonName() << ", Username: " << person.getUsername() << ", Password: " << person.getPassword() << endl;
            personFound = true;
            break;
        }
    }

    if (!personFound) {
        cout << "Person with ID " << personID << " not found!" << endl;
    }

    file.close();
}

Person *Database::login(string username, string password)
{
    for (int i = 0; i < Database::people.size(); i++)
    {
        cout << username << endl;
        cout << Database::people[i]->getUsername() << endl;
        if (Database::people[i]->getUsername() == username && Database::people[i]->getPassword() == password)
        {
            return Database::people[i];
        }
    }
    return nullptr;
}

void Database::calculateAndPrintSolvedFaultRate(const vector<Person*>& people, Fault* faultList, int engineerId) {
    for (Person* person : people) {
        const Engineer* engineer = dynamic_cast<const Engineer*>(person);
        if (engineer && engineer->getPersonID() == engineerId) {
            // Mühendis bulundu
            // Operatör aşırı yükleme kullanarak oranın hesaplanması
            float solveRate = *engineer / faultList;

            // Sonucun ekrana yazdırılması
            cout << "Mühendis ID'si " << engineer->getPersonID() << " için Çözülen Hata Oranı: " << solveRate * 100 << "%" << endl;
            return;  // Mühendis bulundu, işlem tamamlandı.
        }
    }

    cout << "ID'si " << engineerId << " olan mühendis bulunamadı!" << endl;
}
