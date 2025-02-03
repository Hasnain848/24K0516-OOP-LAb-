#include <iostream>
#include <cstdlib>
using namespace std;
struct Event
{
    string name;
    string date;
    string venue;
    string organizer;
};
void inputEvents(Event *event, int num)
{

    cout << "-----Enter Details for the Events-----" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "           Event " << i + 1 << "          " << endl;
        cout << "Name: ";
        cin >> event[i].name;
        cout << "Date(i.e 20/05/2025): ";
        cin >> event[i].date;
        cout << "Venue: ";
        cin >> event[i].venue;
        cout << "Organizer: ";
        cin >> event[i].organizer;
    }
}
void displayEvents(Event *event, int num)
{
    cout << "\n--------All Events Details---------" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "-----------Event " << i + 1 << " ---------" << endl;
        cout << "Name: " << event[i].name << endl;
        cout << "Date: " << event[i].date << endl;
        cout << "Venue: " << event[i].venue << endl;
        cout << "Organizer: " << event[i].organizer << endl;
    }
}
void SearchEvent(Event *event, int num)
{
    string serachdate;
    int flag = 1;
    cout << "Enter Date(i.e 20/05/2025): ";
    cin >> serachdate;
    for (int i = 0; i < num; i++)
    {
        if (event[i].date == serachdate)
        {
            cout << "-----------Event " << i + 1 << " ---------" << endl;
            cout << "Name: " << event[i].name << endl;
            cout << "Venue: " << event[i].venue << endl;
            cout << "Organizer: " << event[i].organizer << endl;
            flag = 0;
        }
    }
    if (flag == 1)
        cout << "\nSorry No such event found" << endl;
}
int main()
{
    int num;
    cout << "Enter the number of events : ";
    cin >> num;
    Event *event = new Event[num];
    inputEvents(event, num);
    displayEvents(event, num);
    cout << "\nNow you can search any event you enter by date" << endl;
    SearchEvent(event, num);
    delete[] event;
}