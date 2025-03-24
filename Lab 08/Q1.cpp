#include<iostream>
using namespace std;
class DeviceManagment{
    protected:
const string deviceId;
string devicetype;
double powerratting;
bool status;
public:
DeviceManagment(string id="",string type="",double power=0,bool status=false):deviceId(id),devicetype(type),powerratting(power),status(status){}
virtual void turnOn(){
    status =true;
}
virtual void turnoff(){
    status = false;
}
virtual double CalculatePowerusage(int hours)=0;

};
class Light:public DeviceManagment{
public:
Light(string id="",string type="",double power=0,bool status=false):DeviceManagment(id,type,power,status){}
double CalculatePowerusage(int hours)override{
         double power=powerratting*hours;
         return power;
}
};
class Fan:public DeviceManagment{
    float speedfactor;
    public:
Fan(string id="",string type="",double power=0,bool status=false):DeviceManagment(id,type,power,status){}
double CalculatePowerusage(int hours)override{
         double power=powerratting*hours*speedfactor;
         return power;
}

};
class Ac:public DeviceManagment{
    float currenttemp;
    float desiretemp;
    public:
Ac(string id="",string type="",double power=0,bool status=false):DeviceManagment(id,type,power,status){}
double CalculatePowerusage(int hours)override{
         double power=(powerratting*hours*(1-(currenttemp-desiretemp)/100));
         return power;
}

};
class SecuritySystem:public DeviceManagment{
    public:
SecuritySystem(string id="",string type="",double power=0,bool status=false):DeviceManagment(id,type,power,status){}
double CalculatePowerusage(int hours)override{
    if(status==true){
         return powerratting;
         }
else cout<<"Sorry noo on"<<endl;
}
};
class UserManagement{
string userid;
string userrole;
int Accesslevel;
public:
UserManagement(string id,string role,int level):userid(id),userrole(role),Accesslevel(level){}
void viewAccessibleDevces(){
    
}
};