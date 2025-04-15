/*Task 05
Problem: A fitness app wants to help users track calories burned during activities like
running and cycling. Each activity requires unique calculations (e.g., distance vs. speed), but
the app must present results consistently. The system should allow adding new activities
(e.g., swimming) in the future.
Classes and Structure:
• Abstract Class Activity:
o Member Function:
▪ calculateCaloriesBurned(): Pure virtual function to compute calories.

• Derived Class Running:
o Data Members:
▪ distance (double): Stores distance in kilometers.
▪ time (double): Stores duration in minutes.
o Implements calculateCaloriesBurned() for running.
• Derived Class Cycling:

o Data Members:
▪ speed (double): Stores speed in km/h.
▪ time (double): Stores duration in hours.
o Implements calculateCaloriesBurned() for cycling.

Flow:
• Create Running and Cycling objects.
• Display calories burned for each activity.*/
#include <iostream>
using namespace std;
class Activity
{
public:
    virtual void CalculateCaloriesBurned() = 0;
};
class Running : public Activity
{
    double distance, time;
    double weight;

public:
    Running(double distance = 0, double time = 0, double weight = 70)
        : distance(distance), time(time), weight(weight) {}

    void CalculateCaloriesBurned() override
    {
        double calories = distance * weight * 1.036;
        cout << "Running Calories Burned: " << calories << " kcal" << endl;
    }
};
class Cycling : public Activity
{
    double distance, time;
    double weight;

public:
    Cycling(double distance = 0, double time = 0, double weight = 70)
        : distance(distance), time(time), weight(weight) {}

    void CalculateCaloriesBurned() override
    {
        double calories = distance * weight * 0.9; // assume 0.9 calo burned per km per kg while cycling.
        cout << "Cycling Calories Burned: " << calories << " kcal" << endl;
    }
};
int main()
{
    Running run(5, 30, 70);
    Cycling cycle(15, 1, 70);

    Activity *activities[2];
    activities[0] = &run;
    activities[1] = &cycle;

    cout << "=== Fitness App: Calories Burned Tracker ===" << endl
         << endl;

    for (int i = 0; i < 2; i++)
    {
        activities[i]->CalculateCaloriesBurned();
        cout << "-----------------------------------------" << endl;
    }

    return 0;
}
