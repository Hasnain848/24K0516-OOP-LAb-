#include <iostream>
using namespace std;
class DeviceManagment
{
protected:
    const string deviceId;
    string devicetype;
    double powerratting;
    bool status;

public:
    DeviceManagment(string id = "", string type = "", double power = 0, bool status = false) : deviceId(id), devicetype(type), powerratting(power), status(status) {}
    virtual void turnOn()
    {
        status = true;
    }
    virtual void turnoff()
    {
        status = false;
    }
    virtual double CalculatePowerusage(int hours) = 0;
};
class Light : public DeviceManagment
{
public:
    Light(string id = "", string type = "", double power = 0, bool status = false) : DeviceManagment(id, type, power, status) {}
    double CalculatePowerusage(int hours) override
    {
        double power = powerratting * hours;
        return power;
    }
    void turnOn() override
    {
        status = true;
        cout << devicetype << " [ID: " << deviceId << "] turned ON." << endl;
    }
    void turnoff() override
    {
        status = false;
    }
};
class Fan : public DeviceManagment
{
    float speedfactor;

public:
    Fan(string id, string type, double power, int speed) : DeviceManagment(id, type, power), speedfactor(speed) {}

    double CalculatePowerusage(int hours) override
    {
        double power = powerratting * hours * speedfactor;
        return power;
    }
    void turnOn() override
    {
        status = true;
        cout << devicetype << " [ID: " << deviceId << "] turned ON at Speed " << speedfactor << "." << endl;
    }
    void turnoff() override
    {
        status = false;
    }
};
class Ac : public DeviceManagment
{
    float currenttemp;
    float desiretemp;

public:
    Ac(string id, string type, double power, double temp) : DeviceManagment(id, type, power), desiretemp(temp) {}
    double CalculatePowerusage(int hours) override
    {
        double power = (powerratting * hours * (1 - (currenttemp - desiretemp) / 100));
        return power;
    }
    void turnOn() override
    {

        status = true;
        cout << devicetype << " [ID: " << deviceId << "] turned ON. Cooling to " << desiretemp << "C." << endl;
    }

    void turnoff() override
    {
        if (currenttemp > desiretemp)
        {
            currenttemp = desiretemp;
        }
        status = false;
    }
};
class SecuritySystem : public DeviceManagment
{
    int password;

public:
    SecuritySystem(string id = "", string type = "", double power = 0, bool status = false, int pass = 1234)
        : DeviceManagment(id, type, power, status), password(pass) {}

    double CalculatePowerusage(int hours) override
    {
        if (status)
        {
            return powerratting;
        }
        else
        {
            cout << "System is OFF, no power usage." << endl;
            return 0;
        }
    }

    void turnoff() override
    {
        int p;
        cout << "Enter password: ";
        cin >> p;
        if (p == password)
        {
            status = false;
            cout << "Security system turned off." << endl;
        }
        else
        {
            cout << "Incorrect password!" << endl;
        }
    }

    friend void accessSecurityLogs(SecuritySystem &obj);
    friend class MaintenanceTool;
};
class UserManagement
{
protected:
    string userid;
    string userrole;
    int Accesslevel;

public:
    UserManagement(string id, string role, int level) : userid(id), userrole(role), Accesslevel(level) {}
    virtual void viewAccessibleDevces() = 0;
};
class RegularUser : public UserManagement
{
public:
    RegularUser(string id, string role, int level) : UserManagement(id, role, level) {}
    void viewAccessibleDevces() override
    {
        cout << "User: " << userid << "-Accessible Devices" << endl;
        cout << "Led lights" << endl;
        cout << "Split Ac" << endl;
        cout << "Ceiling Fan" << endl;
    }
};
class Maintenancestaff : public UserManagement
{
public:
    Maintenancestaff(string id, string role, int level) : UserManagement(id, role, level) {}
    void viewAccessibleDevces() override
    {
        cout << "User: " << userid << "-Accessible Devices" << endl;
        cout << "Led lights" << endl;
        cout << "Split Ac" << endl;
        cout << "Ceiling Fan" << endl;
        cout << "Security syatem" << endl;
    }
};
class MaintenanceTool
{
public:
    void systemreset(SecuritySystem &obj)
    {
        cout << "Systems are reset" << endl;
        obj.status = false;
    }
    void accessSecurityLogs(SecuritySystem &obj)
    {
        cout << "Mantainence tool access" << endl;
    }
};
void accessSecurityLogs(SecuritySystem &obj)
{
    cout << "Accessing security logs" << endl;
}
int main()
{
  
    RegularUser user1("U001", "Regular User", 1);
    Maintenancestaff user2("U002", "Maintenance Staff", 2);

   
    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    Ac ac1("AC001", "Split AC", 1500, 25);
    SecuritySystem secSys1("S001", "Home Alarm", 100);


    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();


    cout << "\nPower Consumption:" << endl;
    cout << "LED Light: " << light1.CalculatePowerusage(5) << " Watts" << endl;
    cout << "Ceiling Fan: " << fan1.CalculatePowerusage(3) << " Watts" << endl;
    cout << "Split AC: " << ac1.CalculatePowerusage(6) << " Watts" << endl;
    cout << "Security System: " << secSys1.CalculatePowerusage(24) << " Watts (Includes security checks)" << endl;


    cout << "\n";
    user1.viewAccessibleDevces();
    cout << "\n";
    user2.viewAccessibleDevces();

    return 0;
}
