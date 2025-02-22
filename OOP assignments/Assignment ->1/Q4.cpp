/*
Class Diagrams for Question 4: (Excluding getters and setters as the class diagrams were becoming way too long)
+---------------------+
|      Student        |
+---------------------+
| - studentID: string |
| - studentName: string|
| - feesPaid: bool    |
| - cardActive: bool  |
| - stopName: string  |
+---------------------+
| + registerStudent(): void    |
| + payFees(): void           |
| + verifyCard(): void        |
+---------------------+

+---------------------+
|        Route        |
+---------------------+
| - routeID: string   |
| - routeName: string |
| - stops: *string     |
| - numStops: int     |
+---------------------+
| + addStop(string): void    |
| + assignStudent(Student&, string): void |
+---------------------+

+---------------------+
|        Bus          |
+---------------------+
| - busID: string     |
| - busName: string   |
| - assignedRoute: Route* |
+---------------------+
| + assignRoute(Route&): void |
| + recordAttendance(Student&): void |
+---------------------+
*/
#include <iostream>
using namespace std;

class Student
{
private:
    string studentID;
    string studentName;
    bool feesPaid;
    bool cardActive;
    string stopName;

public:
    Student() : studentID(""), studentName(""), feesPaid(false), cardActive(false), stopName("") {}
    Student(string id, string name, bool fees, bool card, string stop)
        : studentID(id), studentName(name), feesPaid(fees), cardActive(card), stopName(stop) {}

    void registerStudent()
    {
        if (studentID == "" || studentName == " ")
        {
            cout << " ERROR: Student details are incomplete! Please enter a valid ID and Name.\n";
            return;
        }
        cout << " Student: " << studentName << " (ID: " << studentID << ") has been registered.\n";
    }

    void payFee()
    {
        if (studentID == "")
        {
            cout << " ERROR: No student registered yet. Please register a student first.\n";
            return;
        }
        feesPaid = true;
        cardActive = true;
        cout << " Student: " << studentName << " (ID: " << studentID << ") has paid the fees.\n";
    }

    void verifyCard()
    {
        if (studentID == "")
        {
            cout << " ERROR: No student registered yet. Please register a student first.\n";
            return;
        }
        if (cardActive)
        {
            cout << studentName << "'s transport card is active.\n";
        }
        else
        {
            cout << " ERROR: " << studentName << "'s transport card is NOT active!\n";
        }
    }
    void setstudentname(string name)
    {
        studentName = name;
    }
    void stestudentid(string id)
    {
        studentID = id;
    }
    void setStopName(string stop)
    {
        stopName = stop;
    }

    string getName()
    {
        return studentName;
    }
};

class Route
{
private:
    string routeID;
    string routeName;
    string *stops;
    int numStops;

public:
    Route() : routeID(""), routeName(""), stops(nullptr), numStops(0) {}

    Route(string id, string name) : routeID(id), routeName(name), stops(nullptr), numStops(0) {}

    ~Route()
    {
        delete[] stops;
    }

    void addStops(int stopNum)
    {
        if (stopNum <= 0)
        {
            cout << " Error: Number of stops must be greater than 0.\n";
            return;
        }

        delete[] stops;
        stops = new string[stopNum];
        numStops = stopNum;

        for (int i = 0; i < stopNum; i++)
        {
            do
            {
                cout << "Enter Stop " << i + 1 << ": ";
                getline(cin, stops[i]);
                if (stops[i] == "" || stops[i] == " ")
                {
                    cout << " ERROR: Stop name cannot be empty! Try again.\n";
                }
            } while (stops[i] == "" || stops[i] == " ");
        }
        cout << " Stops for route: " << routeName << " have been added.\n";
    }

    void assignStudent(Student &student, string stop)
    {
        if (student.getName() == "" || student.getName() == " ")
        {
            cout << " ERROR: No student registered yet. Please register a student first.\n";
            return;
        }

        if (numStops == 0)
        {
            cout << " ERROR: No stops added for this route: " << routeName << ".\n";
            return;
        }

        bool found = false;
        for (int i = 0; i < numStops; i++)
        {
            if (stops[i] == stop)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            student.setStopName(stop);
            cout << " Student " << student.getName() << " assigned to stop \"" << stop << "\".\n";
        }
        else
        {
            cout << " Stop \"" << stop << "\" not found in route " << routeName << ".\n";
        }
    }

    void displayRoute()
    {
        if (routeID == "" || routeName == " ")
        {
            cout << " ERROR: No route has been added yet.\n";
            return;
        }
        cout << "\nRoute ID: " << routeID << ", Name: " << routeName << "\nStops: ";
        for (int i = 0; i < numStops; i++)
        {
            cout << stops[i] << (i < numStops - 1 ? ", " : "");
        }
        cout << endl;
    }
    void setroutename(string name)
    {
        routeName = name;
    }
    void sterouteid(string id)
    {
        routeID = id;
    }
    string getroutname() { return routeName; }
    string getrouteid() { return routeID; }
};

class Bus
{
private:
    string busID;
    string busName;
    Route *assignedRoute;

public:
    Bus() : busID(""), busName(""), assignedRoute(nullptr) {}

    Bus(string id, string name) : busID(id), busName(name), assignedRoute(nullptr) {}

    void assignRoute(Route &route)
    {
        if (route.getrouteid() == "" || route.getroutname() == " ")
        {
            cout << " ERROR: No route added yet. Please add a route first.\n";
            return;
        }
        assignedRoute = &route;
        cout << " Route assigned to Bus " << busName << " (ID: " << busID << ").\n";
    }

    void recordAttendance(Student &student)
    {

        if (student.getName().empty())
        {
            cout << " ERROR: No student registered yet. Please register a student first.\n";
            return;
        }
        cout << " Attendance recorded for: " << student.getName() << ".\n";
    }

    void displayBusDetails()
    {
        if (busID == "" || busName == " ")
        {
            cout << " ERROR: No bus has been added yet.\n";
            return;
        }
        cout << "\n============== Bus Details===============" << endl;
        cout << "\n Bus ID: " << busID << "\n Bus Name: " << busName << endl;
        if (assignedRoute)
        {
            assignedRoute->displayRoute();
        }
        else
        {
            cout << " No route assigned to this bus.\n";
            return;
        }
        cout << "\n===============================================" << endl;
    }
    void setbusname(string name)
    {
        busName = name;
    }
    void stebusid(string id)
    {
        busID = id;
    }
};

int main()
{
    string studid, studname, routid, routname, busname, busid;
    Student student1;
    Route route1;
    Bus bus1;
    int choice;
    string stop;
    do
    {
        cout << "\n FAST TRANSPORT SYSTEM \n";
        cout << "1 Register Student\n";
        cout << "2 Pay Fees\n";
        cout << "3 Verify Card\n";
        cout << "4 Add Route And their Stops\n";
        cout << "5 Assign Student to Stop\n";
        cout << "6 Add Bus and Assign Route to Bus\n";
        cout << "7 Display Bus Details\n";
        cout << "8 Exit\n";
        cout << " Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "\n-----Enter the sudent details-------" << endl;
            cout << "Id: ";
            getline(cin, studid);
            cout << "Name: ";
            getline(cin, studname);
            student1.stestudentid(studid);
            student1.setstudentname(studname);
            student1.registerStudent();
            break;
        case 2:
            student1.payFee();
            break;
        case 3:
            student1.verifyCard();
            break;
        case 4:
            int stopCount;
            cout << "------Enter the Route details------" << endl;
            cout << "ID: ";
            getline(cin, routid);
            cout << "Name: ";
            getline(cin, routname);
            cout << "Enter number of stops: ";
            cin >> stopCount;
            cin.ignore();
            route1.sterouteid(routid);
            route1.setroutename(routname);
            cout << "\nRoute: " << routname << " has been added now add stops details" << endl;
            route1.addStops(stopCount);
            break;
        case 5:
            cout << "Enter stop name: ";
            getline(cin, stop);
            route1.assignStudent(student1, stop);
            break;
        case 6:
            cout << "-------Enter the Bus Details----------" << endl;
            cout << "Id: ";
            getline(cin, busid);
            cout << "Name: ";
            getline(cin, busname);
            bus1.setbusname(busname);
            bus1.stebusid(busid);
            cout << "\nBus: " << busname << " has been added now Assigning the routes" << endl;
            bus1.assignRoute(route1);
            break;
        case 7:
            bus1.displayBusDetails();
            break;
        case 8:
            cout << " Exiting program. Have a great day!\n";
            break;
        default:
            cout << " Invalid choice! Please enter a number from 1-8.\n";
        }
    } while (choice != 8);

    return 0;
}
