#include <iostream>
#include <cstring>
#include "C:/Users/Beyza/Documents/GitHub/FaultTracking-system/header/fault.hpp"
#include "../header/person.hpp"
#include "../header/controller.hpp"
#include "../header/engineer.hpp"
#include "../header/ship.hpp"
#include "../src/person.cpp"
#include "../src/controller.cpp"
#include "../src/engineer.cpp"
#include "../src/ship.cpp"
#include "../src/fault.cpp"
#include "../src/database.cpp"

using namespace std;
void defaultInfo();
int display();

int main()
{
    //vector<Person> people;
    defaultInfo();
    //Database::readPerson();
    display();
    return 0;
}

int display()
{
    Person *account;
    int isLoggedIn = 0;
    Database::MAX_FAULTS;
    Fault *faults;

    int faultCount = 0;
    int userCount = 0;

        cout << "Number of users read: " << userCount << endl;
    while (true)
    {

        string username;
        string password;

        Ship *ship = new Ship(1, "abc");

        if (isLoggedIn)
        {
            int option;
            if (instanceof <Controller>(account))
            {
                // Controller Menü
                cout << "\n--------- Controller Menu ---------\n";
                cout << "1- Add faults\n";
                cout << "2- List faults (unrepaired)\n";
                cout << "3- List faults (repaired)\n";
                cout << "4- Assign engineer to faults\n";
                cout << "5- List faults (given engineer ID)\n";
                cout << "6- Person information (findPerson)\n";
                cout << "7- Delete person\n";
                cout << "8- See the solved fault ratio for engineer\n";
                cout << "9- Exit\n";

                cout << "\nSelect an option: ";
                cin >> option;
                string date;
                string faultDescription;
                FaultType faultType;
                FaultLevel faultLevel;
                int faultId;
                int engineerId;
                    int shipId;
                    int controllerId;
                    int typeId;
                    int typeId1;
                switch (option)
                {
                case 1:
                    cout << "Enter Ship Id:";
                    cin >> shipId;
                    cout << "Enter Controller Id:";
                    cin >> controllerId;
                    cout << "Enter fault type (OIL_PRESSURE, WATER_LEVEL, TEMPERATURE,): )";
                    cin >> typeId;
                    faultType = static_cast<FaultType>(typeId);

                    cout << "Enter fault level (slight, medium, severe):";
                    cin >> typeId1;
                    faultLevel = static_cast<FaultLevel>(typeId1);
                    cout << "Enter date :";

                    cin >> date;
                    cout << "Enter fault description:";

                    cin >> faultDescription;

                    Fault::addFault(faults, faultCount, shipId, controllerId, faultType, faultLevel, date, faultDescription, 0);
                    break;
                case 2:
                    Fault::listUnrepairedProblems(faults, faultCount);
                    break;
                case 3:
                    Fault::listRepairedProblems(faults, faultCount);
                    break;
                case 4:
                    cout << "Enter fault Id:";
                    cin >> faultId;
                    cout << "Enter engineer Id:";
                    cin >> engineerId;
                    Fault::assignEngineerToFault(faults, faultId, engineerId);
                    break;
                case 5:
                    cout << "Enter engineer Id:";
                    cin >> engineerId;
                    listAssignedFaults(faults, faultCount, engineerId);
                    break;
                case 6:
                    cout << "Enter  Engineer Id:";
                    cin >> engineerId;
                    
                    Database::findPerson(engineerId);
                    break;
                case 7:
                    cout << "Enter engineer Id:";
                    cin >> engineerId;
                    Database::deletePersonFromFile(engineerId);
                    break;
                case 8:
                    cout << "Enter engineer Id:";
                    cin >> engineerId;
                    Database::calculateAndPrintSolvedFaultRate(Database::people, faults, engineerId);
                    break;
                case 9:
                    isLoggedIn = false;
                    break;
                default:
                    cout << "Invalid option. Please select [1-9]\n";
                    break;
                }
            }
            else if (instanceof <Engineer>(account))
            {
                // Engineer Menü
                cout << "\n--------- Engineer Menu ---------\n";
                cout << "1- List self assigned faults\n";
                cout << "2- Fix fault\n";
                cout << "3- Exit\n";

                cout << "\nSelect an option: ";
                cin >> option;
                string fixDate;
                string fixDescription;

                switch (option)
                {
                case 1:
                    cout << "Enter engineer Id:";
                    int engineerId;
                    cin >> engineerId;
                    listAssignedFaults(faults, faultCount, engineerId);
                    break;
                case 2:
                    cout << "Enter fault Id:";
                    int faultId;
                    cin >> faultId;
                    cout << "Enter fix date:";
                    cin >> fixDate;
                    cout << "Enter fix description:";
                    cin >> fixDescription;
                    fixFault(faults, faultId, fixDate, fixDescription);
                    break;
                case 3:
                    isLoggedIn = false;
                    break;
                default:
                    cout << "Invalid option. Please select [1-3]\n";
                    break;
                }
            }
        }
        else
            {
                cout << "\nEnter your username: " << flush;
                getline(cin, username);

                cout << "Enter your password: ";
                getline(cin, password);

                cout << "\nLogging in...\n\n";

                account = Database::login(username, password);

                if (account != nullptr)
                {
                    isLoggedIn = 1;
                    continue;
                }
                else
                {
                    cout << "User not found! Please try again.\n";
                    continue;
                }
            }
    }
    return 0;
}
void defaultInfo()
{
   // Person *person0 = new Person(1, "beyza", "beyza", "123");
    Controller *eng1 = new Controller(1, "beyza", "beyza", "123");
    Engineer *person1 = new Engineer(2, "gonul", "gonul", "123");
    Engineer *person2 = new Engineer(3, "yusuf", "yusuf", "123");
    Engineer *person3 = new Engineer(4, "yasar", "yasar", "123");
    Engineer *person4 = new Engineer(5, "a", "a", "123");
    Engineer *person5 = new Engineer(6, "b", "b", "123");
    Engineer *person6 = new Engineer(7, "c", "c", "123");

    // Make sure to add these Person pointers to your 'people' vector in the Database class.
    /* Database::people.push_back(person0);
     Database::people.push_back(person1);
     Database::people.push_back(person2);
     Database::people.push_back(person3);
     Database::people.push_back(person4);
     Database::people.push_back(person5);
     Database::people.push_back(person6);*/
}
