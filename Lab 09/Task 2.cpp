/*Task 02
Problem: A homeowner wants to integrate smart lights and thermostats from different
brands into a single app. The system must provide a unified way to turn devices on/off,
adjust settings, and check statuses without requiring users to interact with brand-specific
interfaces. Future devices (e.g., smart locks) should integrate without altering the core
system.
Classes and Structure:
• Abstract Class SmartDevice:
o Member Functions:

▪ turnOn(): Pure virtual function to activate the device.
▪ turnOff(): Pure virtual function to deactivate the device.
▪ getStatus(): Pure virtual function to return the device’s current state.

• Derived Class LightBulb:
o Data Members:
▪ isOn (bool): Tracks if the light is on/off.
▪ brightness (int): Stores brightness level (0-100%).
o Implements turnOn(), turnOff(), and getStatus() for light control.
• Derived Class Thermostat:
o Data Members:
▪ isOn (bool): Tracks if the thermostat is active.
▪ temperature (double): Stores the current temperature setting.
o Implements turnOn(), turnOff(), and getStatus() for temperature control.

Flow:
• Create LightBulb and Thermostat objects.
• Turn devices on/off and display their statuses.*/
#include <iostream>
using namespace std;
class SmartDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
};

class LightBulb : public SmartDevice
{
    bool isOn;
    int brightness;

public:
    LightBulb(int brightness = 50, bool ison = false) : isOn(ison)
    {
        if (brightness >= 0 && brightness <= 100)
            this->brightness = brightness;
        else
            cout << "Brightness not set" << endl;
    }
    void turnOn() override
    {
        if (isOn)
        {
            cout << "Already on" << endl;
            return;
        }
        isOn = true;
        // cout<<"Bulb is on"<<endl;
    }
    void turnOff() override
    {
        if (!isOn)
        {
            cout << "Already off" << endl;
            return;
        }
        isOn = false;
        // cout<<"Bulb is off"<<endl;
    }
    virtual void getStatus() override
    {
        cout << "Status" << endl;
        cout << "Light is turned:";
        if (isOn)
        {
            cout << " On" << endl;
        }
        else
            cout << " Off" << endl;
    }
};
class Thermostat : public SmartDevice
{
    bool isOn;
    double temperature;

public:
    Thermostat(double temperature = 50, bool ison = false) : isOn(ison), temperature(temperature) {}
    void turnOn() override
    {
        if (isOn)
        {
            cout << "Already on" << endl;
            return;
        }
        isOn = true;
        // cout<<"Bulb is on"<<endl;
    }
    void turnOff() override
    {
        if (!isOn)
        {
            cout << "Already off" << endl;
            return;
        }
        isOn = false;
        // cout<<"Bulb is off"<<endl;
    }
    virtual void getStatus() override
    {
        cout << "Status" << endl;
        cout << "Thermostats is turned:";
        if (isOn)
        {
            cout << " On" << endl;
        }
        else
            cout << " Off" << endl;
    }
};
int main()
{
    SmartDevice *ptr;
    LightBulb l(70);
    Thermostat t(56);
    ptr = &l;
    ptr->turnOn();
    ptr->getStatus();
    ptr->turnOff();
    ptr->getStatus();
    cout << "=======================================" << endl;
    ptr = &t;
    ptr->turnOn();
    ptr->getStatus();
    ptr->turnOff();
    ptr->getStatus();
}
