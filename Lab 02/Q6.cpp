#include <iostream>
#include <string>
using namespace std;
struct Register
{
    int course_id;
    string course_name;
};
struct Student
{
    struct Register s2;
    int student_id;
    double cellno;
    string firstname, lastname, email;
};

int main()
{
    struct Student s1[5];
    cout << "-----Enter the Students Details-----" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << " Student " << i + 1 << " " << endl;
        cout << "Course id: ";
        cin >> s1[i].s2.course_id;
        cin.ignore();
        cout << "Course name: ";
        getline(cin, s1[i].s2.course_name);
        cout << "Student id: ";
        cin >> s1[i].student_id;
        cin.ignore();
        cout << "First name: ";
        getline(cin, s1[i].firstname);
        cout << "Last name: ";
        getline(cin, s1[i].lastname);
        cout << "Cell no: ";
        cin >> s1[i].cellno;
        cin.ignore();
        cout << "Email: ";
        getline(cin, s1[i].email);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "----------Student " << i + 1 << " ---------" << endl;
        cout << "Course id: " << s1[i].s2.course_id << endl;
        cout << "Course Name: " << s1[i].s2.course_name << endl;
        cout << "Student id: " << s1[i].student_id << endl;
        cout << "Name: " << s1[i].firstname << " " << s1[i].lastname << endl;
        cout << "Cell no: " << s1[i].cellno << endl;
        cout << "Email: " << s1[i].email << endl;
    }
}