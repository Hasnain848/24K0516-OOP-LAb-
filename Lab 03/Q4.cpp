#include <iostream>
#include <conio.h>
using namespace std;
class Angle
{
    int degrees;
    float minutes;
    char direction;

public:
    Angle()
    {
        degrees = 0;
        minutes = 0.0;
        direction = ' ';
    }
    Angle(int x, float y, char ch)
    {
        if (isValidAngle(x, y, ch))
        {
            degrees = x;
            minutes = y;
            direction = ch;
        }
        else
        {
            cout << "Invalid values! Setting default values.\n";
            degrees = 0;
            minutes = 0.0;
            direction = ' ';
        }
    }
    void input()
    {
        cout << "\n---------------Enter Details-----------------" << endl;
        while (true)
        {
            cout << "Degrees (0-180 for longitude, 0-90 for latitude): ";
            cin >> degrees;
            if (cin.fail() || degrees < 0 || degrees > 180)
            {
                cin.clear();
                cout << "Invalid input! Please enter an integer.\n";
                continue;
            }
            break;
        }

        while (true)
        {
            cout << "Minutes (0 to 59.99): ";
            cin >> minutes;
            if (cin.fail() || minutes < 0 || minutes > 60)
            {
                cin.clear();
                cout << "Invalid input! Please enter an integer.\n";
                continue;
            }
            break;
        }
        while (true)
        {
            cout << "Direction Letter (E, W, N, S): ";
            cin >> direction;
            direction = toupper(direction);
            if (direction == 'E' || direction == 'W' || direction == 'N' || direction == 'S')
            {
                break;
            }
            cout << "Invalid direction! Please enter E, W, N, or S.\n";
        }
    }
    void display()
    {
        cout << "------------------------------------------------";
        cout << "\n->" << degrees << "\xF8" << minutes << "' " << direction << endl;
        if (direction == 'W' || direction == 'w' || direction == 'E' || direction == 'e')
        {
            cout << "Longitude" << endl;
        }
        if (direction == 'N' || direction == 'n' || direction == 'S' || direction == 's')
        {
            cout << "Latitude" << endl;
        }
        cout << "------------------------------------------------\n";
    }
    bool isValidAngle(int d, float m, char dir)
    {
        return ((dir == 'E' || dir == 'W') && d >= 0 && d <= 180 && m >= 0 && m < 60) ||
               ((dir == 'N' || dir == 'S') && d >= 0 && d <= 90 && m >= 0 && m < 60);
    }
};
int main()
{
    Angle a1(149, 34.8, 'W');
    char input;
    cout << "-----------Angle Management System------------" << endl;
    cout << "Enter 1 : to change angle" << endl;
    cout << "Enter 2 :to display angle" << endl;
    cout << "Enter 3 : to exit program" << endl;

    while (true)
    {
        cout << "Choice: ";
        cin >> input;
        if (input == '1')
        {
            a1.input();
        }
        else if (input == '2')
        {
            a1.display();
        }
        else if (input == '3')
        {
            cout << "Exiting Program :)" << endl;
            break;
        }
        else
        {
            cout << "Error Invalid choice" << endl;
        }
    }
    return 0;
}