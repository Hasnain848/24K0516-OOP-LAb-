

#include <iostream>
#include <string>
using namespace std;
class Smartphone {
    private:
    string company;
    string model;
    string displayResolution;
    string ram;
    string rom;
    string storage;
    
    public:
  
    string getCompany() { return company; }
    string getModel() { return model; }
    string getDisplayResolution() { return displayResolution; }
    string getRam() { return ram; }
    string getRom() { return rom; }
    string getStorage() { return storage; }
    
   
    void setCompany(string c) { company = c; }
    void setModel(string m) { model = m; }
    void setDisplayResolution(string dr) { displayResolution = dr; }
    void setRam(string r) { ram = r; }
    void setRom(string ro) { rom = ro; }
    void setStorage(string s) { storage = s; }
    
  
    void makeCall() { cout << "Making a phone call..." << endl; }
    void sendMessage() { cout << "Sending a message..." << endl; }
    void connectToWifi() { cout << "Connecting to the wifi..." << endl; }
    void browseInternet() { cout << "Browsing the internet..." << endl; }
};

int main() {
    Smartphone iPhone,Samsung;
    iPhone.setCompany("Apple");
    iPhone.setModel("iPhone XR");
    iPhone.setDisplayResolution("6.1-inch Super Retina XDR");
    iPhone.setRam("4GB");
    iPhone.setRom("64GB");
    iPhone.setStorage("128GB SSD");
    
    Samsung.setCompany("Samsung");
    Samsung.setModel("Galaxy S21 Ultra");
    Samsung.setDisplayResolution("6.7-inch OLED");
    Samsung.setRam("8GB");
    Samsung.setRom("128GB");
    Samsung.setStorage("256GB SSD");
    
    cout << "Samsung Details:" << endl;
    cout << "Company: " << Samsung.getCompany() << endl;
    cout << "Model: " << Samsung.getModel() << endl;
    cout << "Display Resolution: " << Samsung.getDisplayResolution() << endl;
    cout << "RAM: " << Samsung.getRam() << endl;
    cout << "ROM: " << Samsung.getRom() << endl;
    cout << "Storage: " << Samsung.getStorage() << endl ;
    
 
    
    cout << "iPhone Details:" << endl;
    cout << "Company: " << iPhone.getCompany() << endl;
    cout << "Model: " << iPhone.getModel() << endl;
    cout << "Display Resolution: " << iPhone.getDisplayResolution() << endl;
    cout << "RAM: " << iPhone.getRam() << endl;
    cout << "ROM: " << iPhone.getRom() << endl;
    cout << "Storage: " << iPhone.getStorage() <<endl;
    
    iPhone.makeCall();
    iPhone.sendMessage();
    iPhone.connectToWifi();
    iPhone.browseInternet();
    
    return 0;
}