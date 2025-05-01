/*
class diagram on pdf
*/
#include <iostream>
#include<fstream>
#include<exception>
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

    virtual void payFee() = 0; // Dynamic Polymorphism  // since i have already  done the abstraction concept here 
                       // means as we dont required to made the person object thats why i made it abstract class.
    virtual void verifyCard() = 0; // Dynamic Polymorphism

    void setName(string name)
    {
        this->name = name;
    }
    void setId(string id)
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
    string getID(){return Id;}
    string getStopName()
    {
        return stopname;
    }
    friend ofstream &operator<<(ofstream&out, const Person&s );
    friend ifstream & operator >> (ifstream & in, Person &s);
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
    // friend ofstream &operator<<(ofstream&out, const Person&s );
    // friend ifstream & operator >> (ifstream & in, Person &s);
};
ofstream &operator<<(ofstream &out, const Person &s)
{
    int size;
    size = s.name.size();
    out.write(reinterpret_cast<char *>(&size), sizeof(size));
    out.write(s.name.c_str(), size);

    size = s.Id.size();
    out.write(reinterpret_cast<char *>(&size), sizeof(size));
    out.write(s.Id.c_str(), size);

    out.write(reinterpret_cast<const char *>(&s.feespaid), sizeof(s.feespaid));
    out.write(reinterpret_cast<const char *>(&s.cardactive), sizeof(s.cardactive));

    size = s.stopname.size();
    out.write(reinterpret_cast<char *>(&size), sizeof(size));
    out.write(s.stopname.c_str(), size);
    return out;
}

ifstream &operator>>(ifstream &in, Person &s)
{
    int size;
    in.read(reinterpret_cast<char *>(&size), sizeof(size));
    char *name = new char[size + 1];
    in.read(name, size);
    name[size] = '\0';
    s.setName(name);
    delete[] name;

    in.read(reinterpret_cast<char *>(&size), sizeof(size));
    char *id = new char[size + 1];
    in.read(id, size);
    id[size] = '\0';
    s.setId(id);
    delete[] id;

    in.read(reinterpret_cast<char *>(&s.feespaid), sizeof(s.feespaid));
    in.read(reinterpret_cast<char *>(&s.cardactive), sizeof(s.cardactive));

    in.read(reinterpret_cast<char *>(&size), sizeof(size));
    char *stop = new char[size + 1];
    in.read(stop, size);
    stop[size] = '\0';
    s.setStopName(stop);
    delete[] stop;

    return in;
}

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
        cout << " Teacher: " << name << " (ID: " << Id << ") has been registered.\n";}
       
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
    void assignTeacher(Teachers &teacher, string stop)
    {
        if (teacher.getName() == "" || teacher.getStopName() == " ")
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
            teacher.setStopName(stop);
            cout << " Student " << teacher.getName() << " assigned to stop \"" << stop << "\".\n";
        }
        else
        {
            cout << " Stop \"" << stop << "\" not found in route " << routeName << ".\n";
        }
    }
    void assignStaff(Staff &staff, string stop)
    {
        if (staff.getName() == "" || staff.getStopName() == " ")
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
            staff.setStopName(stop);
            cout << " Student " << staff.getName() << " assigned to stop \"" << stop << "\".\n";
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
    void setNumStops(int num) {
        if (num >= 0) {
            delete[] stops;  // Clean up old memory
            numStops = num;
            stops = new string[numStops];
        }
    }
    string getroutname() { return routeName; }
    string getrouteid() { return routeID; }
    int getstopcount(){return numStops;}
    Route(const Route &other) {
        routeID = other.routeID;
        routeName = other.routeName;
        numStops = other.numStops;
    
        stops = new string[numStops];
        for (int i = 0; i < numStops; i++) {
            stops[i] = other.stops[i];
        }
    }
    Route& operator=(const Route &other) {
        if (this != &other) {
            delete[] stops;
    
            routeID = other.routeID;
            routeName = other.routeName;
            numStops = other.numStops;
    
            stops = new string[numStops];
            for (int i = 0; i < numStops; i++) {
                stops[i] = other.stops[i];
            }
        }
        return *this;
    }
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
    friend ofstream &operator<<(ofstream &out, const Route &route);
    friend ifstream &operator>>(ifstream &in,Route &route);
};
ofstream &operator<<(ofstream &out, const Route &route){
    int size;
size = route.routeName.size();
out.write(reinterpret_cast<char *>(&size), sizeof(size));
out.write(route.routeName.c_str(), size);

size = route.routeID.size();
out.write(reinterpret_cast<char *>(&size), sizeof(size));
out.write(route.routeID.c_str(), size);
out.write(reinterpret_cast<const char*>(&route.numStops),sizeof(route.numStops));
for (int i = 0; i < route.numStops; i++) {
    int len = route.stops[i].size();
    out.write(reinterpret_cast<char*>(&len), sizeof(len));
    out.write(route.stops[i].c_str(), len);
}
return out;
}
ifstream &operator>>(ifstream &in,Route &route){
    int size =0 ;
    in.read(reinterpret_cast<char*>(&size),sizeof(size));
    char *name = new char[size+1];
    in.read(name,size);
    name[size]='\0';
    route.setroutename(name);
    delete[] name;

    in.read(reinterpret_cast<char *>(&size), sizeof(size));
    char *id = new char[size + 1];
    in.read(id, size);
    id[size] = '\0';
    route.sterouteid(id);
    delete[] id;

    
    in.read(reinterpret_cast<char*>(&route.numStops), sizeof(route.numStops));
    delete[] route.stops; // In case it already had data
    route.stops = new string[route.numStops];

    for (int i = 0; i < route.numStops; ++i) {
        in.read(reinterpret_cast<char*>(&size), sizeof(size));
        char *buffer = new char[size + 1];
        in.read(buffer, size);
        buffer[size] = '\0';
        route.stops[i] = buffer;
        delete[] buffer;
    }
 return in;
}

class Bus
{
private:
    string busID;
    string busName;
    Route *assignedRoute; // Aggregation
    // Person* passengers[MAX_PASSENGERS];
    // int passengerCount = 0;
    
    
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
    string getbusid(){return busID;}
    string getbusname(){return busName;}
    friend ofstream& operator<<(ofstream& out, const Bus& bus) {
        int len = bus.busID.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        out.write(bus.busID.c_str(), len);

        len = bus.busName.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        out.write(bus.busName.c_str(), len);
        bool hasroute=false;
        if(bus.assignedRoute){hasroute=true;}
        out.write(reinterpret_cast<const char*>(&hasroute), sizeof(hasroute));
        if(hasroute){
            out << *(bus.assignedRoute);
        }
         return out;
    }

    friend ifstream& operator>>(ifstream& in, Bus& bus) {
        int len;
        char* buffer;

        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        buffer = new char[len + 1];
        in.read(buffer, len);
        buffer[len] = '\0';
        bus.busID = buffer;
        delete[] buffer;

        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        buffer = new char[len + 1];
        in.read(buffer, len);
        buffer[len] = '\0';
        bus.busName = buffer;
        delete[] buffer;

        bool hasroute =false;
        in.read(reinterpret_cast<char*>(&hasroute),sizeof(hasroute));
        if(hasroute){
            Route *r = new Route();
            in >> *r;
            bus.assignedRoute = r;
        }
        else bus.assignedRoute =nullptr;

        return in;
    }
};
class TransportSystem
{
private:
    // Arrays to store entities
    Person **persons;       // Array of pointers to Person objects
    int personCount;
    Route *routes;          // Array of Route objects
    int routeCount;
    Bus *buses;             // Array of Bus objects
    int busCount;

public:
    TransportSystem() : persons(nullptr), personCount(0), routes(nullptr), routeCount(0), buses(nullptr), busCount(0) {}

    ~TransportSystem() 
    {    saveAllPersonsToFile();
        saveAllRoutes();
        saveAllBuses();
        // Free dynamically allocated memory
        for (int i = 0; i < personCount; i++) {
            delete persons[i];
        }
        delete[] persons;
        delete[] routes;
        delete[] buses;
    }

    
    void addPerson(Person *person) 
    {
        
        Person **temp = new Person*[personCount + 1];
        
        
        for (int i = 0; i < personCount; i++) {
            temp[i] = persons[i];
        }
        
        
        temp[personCount] = person;
        
        
        delete[] persons;
        
        
        persons = temp;
        personCount++;
        
       // cout << "Person added successfully.\n";
    }

    // Add a new student
    void addStudent(string id, string name, bool fees = false, bool card = false, string stop = "") 
    {
        Student *student = new Student(id, name, fees, card, stop);
        addPerson(student);
        student->registerStudent();

    }

    // Add a new teacher
    void addTeacher(string id, string name, bool fees = false, bool card = false, string stop = "") 
    {
        Teachers *teacher = new Teachers(id, name, fees, card, stop);
        addPerson(teacher);
        teacher->registerTeacher();
    }

    // Add a new staff member
    void addStaff(string id, string name, bool fees = false, bool card = false, string stop = "") 
    {
        Staff *staff = new Staff(id, name, fees, card, stop);
        addPerson(staff);
        staff->registerStaffmember();
    }

    
    void addRoute(string id, string name, int stopCount) 
    {
        
        Route *temp = new Route[routeCount + 1];
        
        
        for (int i = 0; i < routeCount; i++) {
            temp[i] = routes[i];
        }
        
        
        temp[routeCount] = Route(id, name);
        
       
        delete[] routes;
        
        
        routes = temp;
        routeCount++;
        
        
        routes[routeCount - 1].addStops(stopCount);
        
        cout << "Route added successfully.\n";
        
    }

    
    void addBus(string id, string name) 
    {
        
        Bus *temp = new Bus[busCount + 1];
        
        
        for (int i = 0; i < busCount; i++) {
            temp[i] = buses[i];
        }
        
        
        temp[busCount] = Bus(id, name);
        
        
        delete[] buses;
        
        
        buses = temp;
        busCount++;
        
        cout << "Bus added successfully.\n";
    }

    // Assign route to bus
    void assignRouteToBus(int busIndex, int routeIndex) 
    {
        if (busIndex >= 0 && busIndex < busCount && routeIndex >= 0 && routeIndex < routeCount) {
            buses[busIndex].assignRoute(routes[routeIndex]);
        } else {
            cout << "Invalid bus or route index.\n";
        }
    }

    // Assign student to stop
    void assignPersonToStop(int personIndex, int routeIndex, string stop) 
    {
        if (personIndex >= 0 && personIndex < personCount && routeIndex >= 0 && routeIndex < routeCount) {
            // Check if the person is a student || a Teacher || a Staff
            Student* student = dynamic_cast<Student*>(persons[personIndex]);
            Teachers* teacher = dynamic_cast<Teachers*>(persons[personIndex]);
            Staff* staff = dynamic_cast<Staff*>(persons[personIndex]);
            
            if (student) {
                routes[routeIndex].assignStudent(*student, stop);
            } else if (teacher) {
                routes[routeIndex].assignTeacher(*teacher, stop);
            }
            else if (staff) {
                routes[routeIndex].assignStaff(*staff, stop);
            }
        } else {
            cout << "Invalid person or route index.\n";
        }
    }

   
    void displayAllPersons() 
    {
        if (personCount == 0) {
            cout << "No persons registered.\n";
            return;
        }
        
        cout << "\n==== Registered Persons ====\n";
        for (int i = 0; i < personCount; i++) {
            cout << i+1 << ". Name: " << persons[i]->getName() << "\n";
        }
    }

    
    void displayAllRoutes() 
    {
        if (routeCount == 0) {
            cout << "No routes added.\n";
            return;
        }
        
        cout << "\n==== Available Routes ====\n";
        for (int i = 0; i < routeCount; i++) {
            cout << i+1 << ". ";
            routes[i].displayRoute();
        }
    }

    
    void displayAllBuses() 
    {
        if (busCount == 0) {
            cout << "No buses added.\n";
            return;
        }
        
        
        for (int i = 0; i < busCount; i++) {
            cout << i+1<< ". ";
            buses[i].displayBusDetails();
        }
    }

    
    void payFee(int personIndex) 
    {
        if (personIndex >= 0 && personIndex < personCount) {
            persons[personIndex]->payFee();
        } else {
            cout << "Invalid person index.\n";
        }
    }

    
    void verifyCard(int personIndex) 
    {
        if (personIndex >= 0 && personIndex < personCount) {
            persons[personIndex]->verifyCard();
        } else {
            cout << "Invalid person index.\n";
        }
    }

    
    int getPersonCount() const {
        return personCount;
    }

    
    int getRouteCount() const {
        return routeCount;
    }

    
    int getBusCount() const {
        return busCount;
    }
    void loadAllStudents() {
        try{
        ifstream file("student.bin", ios::binary);
        ifstream teacherFile("teacher.bin", ios::binary);
        ifstream staffFile("staff.bin", ios::binary);

        file.exceptions(ifstream::failbit | ifstream::badbit);
        teacherFile.exceptions(ifstream::failbit | ofstream::badbit);
        staffFile.exceptions(ifstream::failbit | ofstream::badbit);

        int count = 0,teachercount=0,staffcount=0;
        file.read(reinterpret_cast<char*>(&count), sizeof(count));
        teacherFile.read(reinterpret_cast<char*>(&teachercount), sizeof(teachercount));
        staffFile.read(reinterpret_cast<char*>(&staffcount), sizeof(staffcount));
        for (int i = 0; i < count; i++) {
            Student* s = new Student();
            file >> *s;
            addPerson(s);
        }
        file.close();
        for (int i = 0; i < teachercount; i++){
            Teachers * t = new Teachers();
            teacherFile>>*t;
            addPerson(t);
        }
        teacherFile.close();
        for (int i = 0; i < staffcount; i++){
            Staff * st = new Staff();
            staffFile>>*st;
            addPerson(st);
        }
        staffFile.close();
    }
        catch (const ios_base::failure& e){
            cerr << "Error loading students: " << e.what() << endl;
            cout<<"Enter enter to continue "<<endl;
                        getchar();
        }
    }

    
    // Save all persons to file (called on exit)
    void saveAllPersonsToFile() {
       
       try{
         int studentCount = 0, teacherCount = 0, staffCount = 0;
        ofstream studentFile("student.bin", ios::binary);
        ofstream teacherFile("teacher.bin", ios::binary);
        ofstream staffFile("staff.bin", ios::binary);

        studentFile.exceptions(ofstream::failbit | ofstream::badbit);
        teacherFile.exceptions(ofstream::failbit | ofstream::badbit);
        staffFile.exceptions(ofstream::failbit | ofstream::badbit);

        studentFile.write(reinterpret_cast<const char*>(&studentCount), sizeof(studentCount));
        teacherFile.write(reinterpret_cast<const char*>(&teacherCount), sizeof(teacherCount));
        staffFile.write(reinterpret_cast<const char*>(&staffCount), sizeof(staffCount));
    
        for (int i = 0; i < personCount; ++i) {
            if (Student* s = dynamic_cast<Student*>(persons[i])) {
                studentFile << *s;
                studentCount++;
            } else if (Teachers* t = dynamic_cast<Teachers*>(persons[i])) {
                teacherFile << *t;
                teacherCount++;
            } else if (Staff* st = dynamic_cast<Staff*>(persons[i])) {
                staffFile << *st;
                staffCount++;
            }
        }
    
        studentFile.seekp(0);
        teacherFile.seekp(0);
        staffFile.seekp(0);
        studentFile.write(reinterpret_cast<const char*>(&studentCount), sizeof(studentCount));
        teacherFile.write(reinterpret_cast<const char*>(&teacherCount), sizeof(teacherCount));
        staffFile.write(reinterpret_cast<const char*>(&staffCount), sizeof(staffCount));
    
        studentFile.close();
        teacherFile.close();
        staffFile.close();}
        catch (const ios_base::failure& e) {
            cerr << "Error saving persons: " << e.what() << endl;
        }
    }
    
    // Load all routes
    void loadAllRoutes() {
        try{
        ifstream file("route.bin", ios::binary);
        file.exceptions(ifstream::failbit | ifstream::badbit);
        int count = 0;
        file.read(reinterpret_cast<char*>(&count), sizeof(count));
        for (int i = 0; i < count; ++i) {
            Route r;
            file >> r;

            Route *temp = new Route[routeCount + 1];
        for (int i = 0; i < routeCount; i++) {
            temp[i] = routes[i];
        }
        temp[routeCount] = r;
        delete[] routes;
        routes = temp;
        routeCount++;
           // addRoute(r.getrouteid(),r.getroutname(),r.getstopcount());
            
        }
        file.close();}
        catch (const ios_base::failure& e){
            cerr << "Error loading routes: " << e.what() << endl;
        }
    }
    
    // Save all routes
    void saveAllRoutes() {
        try{
        ofstream file("route.bin", ios::binary);
        file.exceptions(ofstream::failbit | ofstream::badbit);
        file.write(reinterpret_cast<const char*>(&routeCount), sizeof(routeCount));
        for (int i = 0; i < routeCount; ++i) {
            file << routes[i];
        }
        file.close();}
        catch (const ios_base::failure& e) {
            cerr << "Error saving Routes: " << e.what() << endl;
        }
    }
    
    void saveAllBuses() {
        try{
        ofstream file("bus.bin", ios::binary);
        file.exceptions(ofstream::failbit | ofstream::badbit);
        file.write(reinterpret_cast<const char*>(&busCount), sizeof(busCount));
        for (int i = 0; i < busCount; ++i) {
            file << buses[i];
        }
        file.close();}
        catch (const ios_base::failure& e) {
            cerr << "Error saving Buses: " << e.what() << endl;
        }
    }
    
    // Load all buses
    void loadAllBuses() {
        try{
        ifstream file("bus.bin", ios::binary);
        file.exceptions(ifstream::failbit | ifstream::badbit);
        int count = 0;
        file.read(reinterpret_cast<char*>(&count), sizeof(count));
        for (int i = 0; i < count; ++i) {
            Bus b;
            file >> b;

            Bus *temp = new Bus[busCount + 1];
            for (int i = 0; i < busCount; i++) {
                temp[i] = buses[i];
            }
            temp[busCount] = b;
            delete[] buses;
            buses = temp;
            busCount++;
            //addBus(b.getbusid(),b.getbusname());
        }
        file.close();}
        catch (const ios_base::failure& e) {
            cerr << "Error loading buses: " << e.what() << endl;
            
        }
    }
    
};
void clearInputBuffer() {
    char c;
    while ((c = cin.get()) != '\n' && c != EOF);
}

class InputException : public exception {
    public:
         const char* what() const noexcept override{
          return("Invalid input: Please enter a number");
    }
    };

int main()
{
    TransportSystem ts;
    ts.loadAllStudents();
    ts.loadAllRoutes();
    ts.loadAllBuses();

    int choice, subChoice;
    string id, name, stop;

    do
    {  
         system("cls");
        cout << "==============================" << endl;
        cout << "| MY Name: M Hasnain Siddiqui |" << endl;
        cout << "| Roll num: 24K-0516         |" << endl;
        cout << "==============================" << endl;
        cout << "\n FAST TRANSPORT SYSTEM \n";
        cout << "1. Admin Menu\n";
        cout << "2. Customer Menu\n";
        cout << "3. Exit\n";
        
       try{
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            clearInputBuffer();
            throw InputException();
        }
        cin.ignore();
       // try{
        switch (choice)
        {
        case 1: // Admin Menu
            do
            {   system("cls");
                cout << "\n=== ADMIN MENU ===\n";
                cout << "1. Add Route\n";
                cout << "2. Add Bus\n";
                cout << "3. Assign Route to Bus\n";
                cout << "4. Display All Routes\n";
                cout << "5. Display All Buses\n";
                cout << "6. Back to Main Menu\n";
                try{
                cout << "Enter your choice: ";
                cin >> subChoice;
                if (cin.fail()) {
                    cin.clear();
                    clearInputBuffer();
                    throw InputException();
                }

                cin.ignore();

                switch (subChoice)
                {
                case 1: // Add Route
                    {   system("cls");
                        string routeId, routeName;
                        int stopCount;
                        
                        cout << "------Enter the Route details------" << endl;
                        cout << "ID: ";
                        getline(cin, routeId);
                        cout << "Name: ";
                        getline(cin, routeName);
                        try{
                        cout << "Enter number of stops: ";
                        cin >> stopCount;
                        if (cin.fail()) {
                            cin.clear();
                            clearInputBuffer();
                            throw InputException();
                        }
                        cin.ignore();
                        
                        ts.addRoute(routeId, routeName, stopCount);
                        cout<<"Enter enter to continue "<<endl;
                        getchar();}
                        catch (const InputException& e) {
                            cout << "Input error: " << e.what() << endl;
                            cout << "Press enter to continue...";
                            getchar();
                        }
                    }
                    break;
                    
                case 2: // Add Bus
                    {    system("cls");
                        string busId, busName;
                        
                        cout << "-------Enter the Bus Details----------" << endl;
                        cout << "Id: ";
                        getline(cin, busId);
                        cout << "Name: ";
                        getline(cin, busName);
                        
                        ts.addBus(busId, busName);
                        cout<<"Enter enter to continue "<<endl;
                        getchar();
                    }
                    break;
                    
                case 3: // Assign Route to Bus
                    {   system("cls");
                        int busIndex, routeIndex;
                        try{
                        ts.displayAllBuses();
                        cout << "Enter bus index: ";
                        cin >> busIndex;
                        if (cin.fail()) {
                            cin.clear();
                            clearInputBuffer();
                            throw InputException();
                        }
                        
                        ts.displayAllRoutes();
                        cout << "Enter route index: ";
                        cin >> routeIndex;
                        if (cin.fail()) {
                            cin.clear();
                            clearInputBuffer();
                            throw InputException();
                        }
                        cin.ignore();
                        
                        ts.assignRouteToBus(busIndex-1, routeIndex-1);
                        cout<<"Enter enter to continue "<<endl;
                        getchar();}
                        catch (const InputException& e) {
                            cout << "Input error: " << e.what() << endl;
                            cout << "Press enter to continue...";
                            getchar();
                        }
                    }
                    break;
                    
                case 4: // Display All Routes
                system("cls");
                    ts.displayAllRoutes();
                    cout<<"Enter enter to continue "<<endl;
                        getchar();
                    break;
                    
                case 5: // Display All Buses
                system("cls");
                    ts.displayAllBuses();
                    cout<<"Enter enter to continue "<<endl;
                        getchar();
                    break;
                    
                case 6:
                    cout << "Returning to main menu.\n";
                    break;
                    
                default:
                    cout << "Invalid choice! Please enter a number from 1-6.\n";
                }}catch (const InputException& e) {
                    cout << "Input error: " << e.what() << endl;
                    cout << "Press enter to continue...";
                    getchar();
                }
            } while (subChoice != 6);
            break;

        case 2: // Customer Menu
            do
            {
                system("cls");
                cout << "\n=== CUSTOMER MENU ===\n";
                cout << "1. Register Student\n";
                cout << "2. Register Teacher\n";
                cout << "3. Register Staff Member\n";
                cout << "4. Pay Fees\n";
                cout << "5. Verify Card\n";
                cout << "6. Assign Person to Stop\n";
                cout << "7. Display All Persons\n";
                cout << "8. Back to Main Menu\n";
               try{
                cout << "Enter your choice: ";
                cin >> subChoice;
                if (cin.fail()) {
                    cin.clear();
                    clearInputBuffer();
                    throw InputException();
                }
                cin.ignore();

                switch (subChoice)
                {
                case 1: // Register Student
                    {
                        system("cls");
                        cout << "\n-----Enter the student details-------" << endl;
                        cout << "Id: ";
                        getline(cin, id);
                        cout << "Name: ";
                        getline(cin, name);
                        
                        ts.addStudent(id, name);
                        cout<<"Enter enter to continue "<<endl;
                        getchar();
                    }
                    break;
                    
                case 2: // Register Teacher
                    {
                        system("cls");
                        cout << "\n-----Enter the teacher details-------" << endl;
                        cout << "Id: ";
                        getline(cin, id);
                        cout << "Name: ";
                        getline(cin, name);
                        
                        ts.addTeacher(id, name);
                        cout<<"Enter enter to continue "<<endl;
                        getchar();
                    }
                    break;
                    
                case 3: // Register Staff Member
                    {
                        system("cls");
                        cout << "\n-----Enter the staff member details-------" << endl;
                        cout << "Id: ";
                        getline(cin, id);
                        cout << "Name: ";
                        getline(cin, name);
                        
                        ts.addStaff(id, name);
                        cout<<"Enter enter to continue "<<endl;
                        getchar();
                    }
                    break;
                    
                case 4: // Pay Fees
                    {    system("cls");
                        try{
                        int personIndex;
                        
                        ts.displayAllPersons();
                        cout << "Enter person index: ";
                        cin >> personIndex;
                        if (cin.fail()) {
                            cin.clear();
                            clearInputBuffer();
                            throw InputException();
                        }
                        cin.ignore();
                        
                        ts.payFee(personIndex-1);
                        cout<<"Enter enter to continue "<<endl;
                        getchar();}
                        catch (const InputException& e) {
                            cout << "Input error: " << e.what() << endl;
                            cout << "Press enter to continue...";
                            getchar();
                        }
                    }
                    break;
                    
                case 5: // Verify Card
                    {   system("cls");
                        try{
                        int personIndex;
                        
                        ts.displayAllPersons();
                        cout << "Enter person index: ";
                        cin >> personIndex;
                        if (cin.fail()) {
                            cin.clear();
                            clearInputBuffer();
                            throw InputException();
                        }
                        cin.ignore();
                        
                        ts.verifyCard(personIndex-1);
                        cout<<"Enter enter to continue "<<endl;
                        getchar();}
                        catch (const InputException& e) {
                            cout << "Input error: " << e.what() << endl;
                            cout << "Press enter to continue...";
                            getchar();
                        }
                    }
                    break;
                    
                case 6: // Assign Person to Stop
                    {
                        system("cls");
                        try{
                        int personIndex, routeIndex;
                        
                        ts.displayAllPersons();
                        cout << "Enter person index: ";
                        cin >> personIndex;
                        if (cin.fail()) {
                            cin.clear();
                            clearInputBuffer();
                            throw InputException();
                        }
                        
                        ts.displayAllRoutes();
                        cout << "Enter route index: ";
                        cin >> routeIndex;
                        if (cin.fail()) {
                            cin.clear();
                            clearInputBuffer();
                            throw InputException();
                        }
                        cin.ignore();
                        
                        cout << "Enter stop name: ";
                        getline(cin, stop);
                        
                        ts.assignPersonToStop(personIndex-1, routeIndex-1, stop);
                        cout<<"Enter enter to continue "<<endl;
                        getchar();}
                        catch (const InputException& e) {
                            cout << "Input error: " << e.what() << endl;
                            cout << "Press enter to continue...";
                            getchar();
                        }
                    }
                    break;
                    
                case 7: // Display All Persons
                    system("cls");
                    ts.displayAllPersons();
                    cout<<"Enter enter to continue "<<endl;
                        getchar();
                    break;
                    
                case 8:
                    cout << "Returning to main menu.\n";
                    break;
                    
                default:
                    cout << "Invalid choice! Please enter a number from 1-8.\n";
                }}
                catch (const InputException& e) {
                    cout << "Input error: " << e.what() << endl;
                    cout << "Press enter to continue...";
                    getchar();
                }
            } while (subChoice != 8);
            break;

        case 3:
            cout << "Exiting program. Have a great day:)\n";
            break;
            
        default:
            cout << "Invalid choice! Please enter a number from 1-3.\n";
        }}
        catch (const InputException& e) {
            cout << "Input error: " << e.what() << endl;
            cout << "Press enter to continue...";
            getchar();
        }
        catch (const exception &e) {
            cout << "Runtime exception: " << e.what() << endl;
            getchar();
        }
     } while (choice != 3);

    return 0;
}