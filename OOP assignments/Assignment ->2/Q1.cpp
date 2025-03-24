/*
class diagram on pdf
*/
#include <iostream>
using namespace std;
class Person
{
protected:
    string name, Id;
    bool feespaid;
    bool cardactive;
    string stopname;

public:
    Person() : Id(""), name(""), feespaid(false), cardactive(false), stopname("") {}
    Person(string id, string name, bool fees, bool card, string stop)
        : Id(id), name(name), feespaid(fees), cardactive(card), stopname(stop) {}

    virtual void payFee() = 0; // Dynamic Polymorphism

    virtual void verifyCard() = 0; // Dynamic Polymorphism

    void setstudentname(string name)
    {
        this->name = name;
    }
    void stestudentid(string id)
    {
        Id = id;
    }
    void setStopName(string stop)
    {
        stopname = stop;
    }
    string getName()
    {
        return name;
    }
};
class Student : public Person
{
public:
    Student(string id = "", string name = "", bool fees = false, bool card = false, string stop = "")
        : Person(id, name, fees, card, stop) {}

    void registerStudent()
    {
        if (Id == "" || name == " ")
        {
            cout << " ERROR: Student details are incomplete! Please enter a valid ID and Name.\n";
            return;
        }
        cout << " Student: " << name << " (ID: " << Id << ") has been registered.\n";
    }

    void payFee() override
    {
        if (Id == "")
        {
            cout << " ERROR: No student registered yet. Please register a student first.\n";
            return;
        }
        feespaid = true;
        cardactive = true;
        cout << " Student: " << name << " (ID: " << Id << ") has paid the fees.\n";
    }

    void verifyCard() override
    {
        if (Id == "")
        {
            cout << " ERROR: No student registered yet. Please register a student first.\n";
            return;
        }
        if (cardactive)
        {
            cout << name << "'s transport card is active.\n";
        }
        else
        {
            cout << " ERROR: " << name << "'s transport card is NOT active!\n";
        }
    }
};
class Teachers : public Person
{
public:
    Teachers(string id = "", string name = "", bool fees = false, bool card = false, string stop = "")
        : Person(id, name, fees, card, stop) {}
    void registerTeacher()
    {
        if (Id == "" || name == " ")
        {
            cout << " ERROR: Teacher details are incomplete! Please enter a valid ID and Name.\n";
            return;
        }
        cout << " Teacher: " << name << " (ID: " << Id << ") has been registered.\n";
    }
    void payFee() override
    {
        if (Id == "")
        {
            cout << " ERROR: No Teacher registered yet. Please register a Teacher first.\n";
            return;
        }
        feespaid = true;
        cardactive = true;
        cout << " Teacher: " << name << " (ID: " << Id << ") has paid the fees.\n";
    }

    void verifyCard() override
    {
        if (Id == "")
        {
            cout << " ERROR: No Teacher registered yet. Please register a Teacher first.\n";
            return;
        }
        if (cardactive)
        {
            cout << name << "'s transport card is active.\n";
        }
        else
        {
            cout << " ERROR: " << name << "'s transport card is NOT active!\n";
        }
    }
};
class Staff : public Person
{
public:
    Staff(string id = "", string name = "", bool fees = false, bool card = false, string stop = "")
        : Person(id, name, fees, card, stop) {}
    void registerStaffmember()
    {
        if (Id == "" || name == " ")
        {
            cout << " ERROR: Staff details are incomplete! Please enter a valid ID and Name.\n";
            return;
        }
        cout << " Staff member: " << name << " (ID: " << Id << ") has been registered.\n";
    }
    void payFee() override
    {
        if (Id == "")
        {
            cout << " ERROR: No Staff member registered yet. Please register a member first.\n";
            return;
        }
        feespaid = true;
        cardactive = true;
        cout << " Member: " << name << " (ID: " << Id << ") has paid the fees.\n";
    }

    void verifyCard() override
    {
        if (Id == "")
        {
            cout << " ERROR: No Staff member registered yet. Please register a member first.\n";
            return;
        }
        if (cardactive)
        {
            cout << name << "'s transport card is active.\n";
        }
        else
        {
            cout << " ERROR: " << name << "'s transport card is NOT active!\n";
        }
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

    bool operator==(const Route &r1)
    { // Static Polymorphism by Operator overloading
        bool flag = true;
        if (routeID == r1.routeID && routeName == r1.routeName && numStops == numStops)
        {
            for (int i = 0; i < numStops; i++)
            {
                if (stops[i] != r1.stops[i])
                {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
        else
            return false;
    }
};
class Bus
{
private:
    string busID;
    string busName;
    Route *assignedRoute; // Aggregation

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

    Teachers teacher1("T001", "Dr. Ali", false, false, "Stop2");
    Staff staff1("S001", "John", false, false, "Stop3");
    Person *personPtr;

    do
    {
        cout << "==============================" << endl;
        cout << "| MY Name:M Hasnain Siddiqui |" << endl;
        cout << "| Roll num: 24K-0516         |" << endl;
        cout << "==============================" << endl;
        cout << "\n FAST TRANSPORT SYSTEM \n";
        cout << "1 Register Student\n";
        cout << "2 Pay Fees\n";
        cout << "3 Verify Card\n";
        cout << "4 Add Route And their Stops\n";
        cout << "5 Assign Student to Stop\n";
        cout << "6 Add Bus and Assign Route to Bus\n";
        cout << "7 Display Bus Details\n";
        cout << "8 Demonstrate Polymorphism\n"; // Added option for polymorphism
        cout << "9 Exit\n";
        cout << " Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "\n-----Enter the student details-------" << endl;
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
            // Polymorphism Demonstration
            cout << "\n=== Demonstrating Polymorphism ===\n";

            personPtr = &student1;
            cout << "Student Paying Fee: ";
            personPtr->payFee();

            personPtr = &teacher1;
            cout << "Teacher Paying Fee: ";
            personPtr->payFee();

            personPtr = &staff1;
            cout << "Staff Paying Fee: ";
            personPtr->payFee();
            break;
        case 9:
            cout << " Exiting program. Have a great day:)\n";
            break;
        default:
            cout << " Invalid choice! Please enter a number from 1-9.\n";
        }
    } while (choice != 9);

    return 0;
}
