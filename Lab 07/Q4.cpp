#include <iostream>
using namespace std;
class Person
{
protected:
    string name, id, address, phonenumber, email;

public:
    Person(string name, string id, string address, string phonenumber, string email) : name(name), id(id), address(address), phonenumber(phonenumber), email(email) {}

    virtual void displayinfo()
    {
        cout << "========Person Details========" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone number: " << phonenumber << endl;
        cout << "Email: " << email << endl;
    }
    void updateinfo(string n, string i, string add, string number, string mail)
    {
        name = n;
        id = i;
        address = add;
        phonenumber = number;
        email = mail;
    }
    string getname() { return name; }
};
class Student : public Person
{
    int coursesenrolled, enrollmentyear;
    float GPA;

public:
    Student(string name, string id, string address, string phonenumber, string email, int courseenrol, int year, float gpa) : Person(name, id, address, phonenumber, email), coursesenrolled(courseenrol), enrollmentyear(year), GPA(gpa) {}

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Courses Enrolled: " << coursesenrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrolment Year: " << enrollmentyear << endl;
        cout << "==============================" << endl;
    }
};
class Professor : public Person
{
    string Department;
    int coursestaught;
    double salary;

public:
    Professor(string name, string id, string address, string phonenumber, string email, string department, int courses, double sal) : Person(name, id, address, phonenumber, email), Department(department), coursestaught(courses), salary(sal) {}

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Department: " << Department << endl;
        cout << "Courses taught: " << coursestaught << endl;
        cout << "Salary: " << salary << endl;
        cout << "==============================" << endl;
    }
};
class Staff : public Person
{
    string Department, position;
    double salary;

public:
    Staff(string name, string id, string address, string phonenumber, string email, string Department, string position, double salary) : Person(name, id, address, phonenumber, email), Department(Department), position(position), salary(salary) {}

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Department: " << Department << endl;
        cout << "Position : " << position << endl;
        cout << "Salary: " << salary << endl;
        cout << "==============================" << endl;
    }
};
class Course
{
    int courseid, credits;
    string coursename, schedule, instructor;
    Student *stud[50];
    int studcount;

public:
    Course(int courseid, string cname, int credits, string instructor, string schedule) : courseid(courseid), coursename(cname), credits(credits), instructor(instructor), schedule(schedule), studcount(0)
    {
        for (int i = 0; i < 50; i++)
        {
            stud[i] = nullptr;
        }
    }

    void registerStudent(Student *s)
    {
        if (s == nullptr)
        {
            cout << "Error: Null student pointer provided. Registration failed." << endl;
            return;
        }
        if (studcount < 50)
        {
            stud[studcount] = s;
            studcount++;
            cout << "Student name " << s->getname() << " has been registered" << endl;
        }
        else
            cout << "Error: Maximum student capacity reached for " << coursename << "." << endl;
    }
    void Calculategrades()
    {
        cout << "Calculating grades for course name ->" << coursename << endl;
    }
};
int main()
{

    Student s1("Ali", "S001", "Karachi", "123456", "ali@example.com", 5, 2023, 3.8);
    Student s2("Sara", "S002", "Lahore", "987654", "sara@example.com", 4, 2022, 3.5);
    Professor p1("Dr. Ahmed", "P001", "Islamabad", "567890", "ahmed@example.com", "CS", 3, 100000);
    Staff st1("Mr. Khan", "ST001", "Faisalabad", "345678", "khan@example.com", "HR", "Manager", 75000);
    cout << "\n===== Initial Details =====" << endl;
    s1.displayinfo();
    p1.displayinfo();
    st1.displayinfo();
    Course cppCourse(101, "C++ Programming", 3, "Dr. Ahmed", "Mon-Wed-Fri");
    cppCourse.registerStudent(&s1);
    cppCourse.registerStudent(&s2);

    cppCourse.Calculategrades();

    return 0;
}