#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int vehicleId;
    static int trackDeliveries;
    float speed, capacity, energyEfficiency;

public:
    Vehicle() : vehicleId(0), speed(0), capacity(0), energyEfficiency(0)
    {
        trackDeliveries++;
    }

    Vehicle(int id, float spd, float cap, float eff) : vehicleId(id), speed(spd), capacity(cap), energyEfficiency(eff)
    {
        if (id < 0)
        {
            cout << "Error: Vehicle ID cannot be negative. Setting to default." << endl;
            vehicleId = 0;
        }
        if (spd <= 0)
        {
            cout << "Error: Speed must be positive. Setting to default." << endl;
            speed = 1.0;
        }
        if (cap <= 0)
        {
            cout << "Error: Capacity must be positive. Setting to default." << endl;
            capacity = 1.0;
        }
        if (eff <= 0)
        {
            cout << "Error: Energy efficiency must be positive. Setting to default." << endl;
            energyEfficiency = 1.0;
        }
        trackDeliveries++;
    }

    virtual void CalculateOptimalDeliveryRoute() = 0;
    virtual void EstimateDeliveryTime() = 0;

    int getTrack() const { return trackDeliveries; }

    bool operator==(const Vehicle &other)
    {
        return (speed == other.speed) && (capacity == other.capacity) && (energyEfficiency == other.energyEfficiency);
    }

    friend void resolveConflict(Vehicle &v1, Vehicle &v2);

    virtual void command(string action, int packageID)
    {
        if (packageID <= 0)
        {
            cout << "Error: Invalid package ID. Command rejected." << endl;
            return;
        }
        cout << "Vehicle #" << vehicleId << " executing command: " << action << " for Package " << packageID << endl;
    }

    virtual void command(string action, int packageID, string urgency)
    {
        if (packageID <= 0)
        {
            cout << "Error: Invalid package ID. Command rejected." << endl;
            return;
        }
        if (urgency != "urgent" && urgency != "normal")
        {
            cout << "Warning: Unrecognized urgency level. Proceeding with standard protocol." << endl;
        }
        cout << "Vehicle #" << vehicleId << " executing command: " << action << " for Package " << packageID
             << " with urgency: " << urgency << endl;
    }
    int getVehicleId() { return vehicleId; }
};

int Vehicle::trackDeliveries = 0;

class RamzanDrone : public Vehicle
{
    float maxAltitude;
    bool speedActive;
    int batteryLife;

public:
    RamzanDrone(int id) : Vehicle(id, 100, 5, 85), maxAltitude(500), speedActive(false), batteryLife(100) {}

    void CalculateOptimalDeliveryRoute() override
    {
        cout << "RamzanDrone calculating aerial delivery route..." << endl;
    }

    void EstimateDeliveryTime() override
    {
        cout << "RamzanDrone estimating delivery time based on wind speed and altitude..." << endl;
    }

    void command(string action, int packageID, string urgency) override
    {
        if (packageID <= 0)
        {
            cout << "Error: Invalid package ID. Drone command rejected." << endl;
            return;
        }

        if (urgency == "urgent")
        {
            speedActive = true;
            cout << "RamzanDrone #" << vehicleId << " activating high-speed mode for Iftar delivery!" << endl;
        }
        Vehicle::command(action, packageID, urgency);
    }
};

class RamzanTimeShip : public Vehicle
{
    bool timeValidation;

public:
    RamzanTimeShip(int id) : Vehicle(id, 500, 10, 95), timeValidation(false) {}

    void CalculateOptimalDeliveryRoute() override
    {
        cout << "RamzanTimeShip verifying historical accuracy for delivery..." << endl;
    }

    void EstimateDeliveryTime() override
    {
        cout << "RamzanTimeShip estimating delivery time by checking time-travel stability..." << endl;
    }

    void command(string action, int packageID, string urgency) override
    {
        if (packageID <= 0)
        {
            cout << "Error: Invalid package ID. TimeShip command rejected." << endl;
            return;
        }

        if (urgency == "urgent")
        {
            timeValidation = true;
            cout << "RamzanTimeShip #" << vehicleId << " ensuring historical accuracy before urgent delivery!" << endl;
        }
        Vehicle::command(action, packageID, urgency);
    }
};
class RamzanHyperPod : public Vehicle
{
    float tunnelDepth;
    bool bulkDeliveryMode;

public:
    RamzanHyperPod(int id) : Vehicle(id, 300, 50, 90), tunnelDepth(100), bulkDeliveryMode(false) {}

    void CalculateOptimalDeliveryRoute() override
    {
        cout << "RamzanHyperPod navigating underground tunnels for bulk delivery..." << endl;
    }

    void EstimateDeliveryTime() override
    {
        cout << "RamzanHyperPod calculating time based on tunnel congestion..." << endl;
    }

    void command(string action, int packageID) override
    {
        if (packageID <= 0)
        {
            cout << "Error: Invalid package ID. HyperPod command rejected." << endl;
            return;
        }

        cout << "RamzanHyperPod #" << vehicleId << " preparing tunnel network for package #" << packageID << endl;
        Vehicle::command(action, packageID);
    }

    void command(string action, int packageID, string urgency) override
    {
        if (packageID <= 0)
        {
            cout << "Error: Invalid package ID. HyperPod command rejected." << endl;
            return;
        }

        if (urgency == "urgent")
        {
            bulkDeliveryMode = true;
            cout << "RamzanHyperPod #" << vehicleId << " activating express tunnel routes for urgent bulk delivery!" << endl;
        }
        Vehicle::command(action, packageID, urgency);
    }
};

void resolveConflict(Vehicle &v1, Vehicle &v2)
{
    if (v1.speed > v2.speed)
    {
        cout << "Conflict resolved: Vehicle #" << v1.vehicleId << " is chosen for faster delivery!" << endl;
    }
    else if (v2.speed > v1.speed)
    {
        cout << "Conflict resolved: Vehicle #" << v2.vehicleId << " is chosen for faster delivery!" << endl;
    }
    else
    {
        cout << "Both vehicles are equally fast. Using energy efficiency as the deciding factor..." << endl;
        if (v1.energyEfficiency > v2.energyEfficiency)
            cout << "Vehicle #" << v1.vehicleId << " selected based on efficiency!" << endl;
        else
            cout << "Vehicle #" << v2.vehicleId << " selected based on efficiency!" << endl;
    }
}

void displayMenu()
{
    cout << "\n==================================================" << endl;
    cout << "    RAMZAN BOX DELIVERY SYSTEM - CONTROL PANEL    " << endl;
    cout << "==================================================" << endl;
    cout << "1. Select RamzanDrone" << endl;
    cout << "2. Select RamzanTimeShip" << endl;
    cout << "3. Select RamzanHyperPod" << endl;
    cout << "4. Calculate optimal delivery route" << endl;
    cout << "5. Estimate delivery time" << endl;
    cout << "6. Issue delivery command" << endl;
    cout << "7. Resolve conflict between vehicles" << endl;
    cout << "8. View total deliveries" << endl;
    cout << "9. Exit" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    RamzanDrone drone1(101);
    RamzanTimeShip timeShip1(202);
    RamzanHyperPod hyperPod1(303);
    Vehicle *selectedVehicle = nullptr;
    Vehicle *secondVehicle = nullptr;

    int choice = 0;
    bool running = true;
    cout << "===============================" << endl;
    cout << "| MY Name: M Hasnain Siddiqui |" << endl;
    cout << "| Roll num: 24K-0516          |" << endl;
    cout << "===============================" << endl;
    cout << "\nWelcome to the RamzanBox Delivery System (Year 2030)" << endl;
    cout << "AI-Driven Food and Essential Supplies Delivery for Ramzan" << endl;
    while (running)
    {
        displayMenu();
        cin >> choice;
        cin.clear();
        while (cin.get() != '\n')
            ;

        switch (choice)
        {
        case 1:
            selectedVehicle = &drone1;
            cout << "\nRamzanDrone #" << drone1.getVehicleId() << " selected!" << endl;
            break;

        case 2:
            selectedVehicle = &timeShip1;
            cout << "\nRamzanTimeShip #" << timeShip1.getVehicleId() << " selected!" << endl;
            break;

        case 3:
            selectedVehicle = &hyperPod1;
            cout << "\nRamzanHyperPod #" << hyperPod1.getVehicleId() << " selected!" << endl;
            break;

        case 4:
            if (selectedVehicle)
            {
                cout << "\n--- Calculating Optimal Route ---\n";
                selectedVehicle->CalculateOptimalDeliveryRoute();
            }
            else
            {
                cout << "\nError: No vehicle selected. Please select a vehicle first." << endl;
            }
            break;

        case 5:
            if (selectedVehicle)
            {
                cout << "\n--- Estimating Delivery Time ---\n";
                selectedVehicle->EstimateDeliveryTime();
            }
            else
            {
                cout << "\nError: No vehicle selected. Please select a vehicle first." << endl;
            }
            break;

        case 6:
        {
            if (selectedVehicle)
            {
                int packageID;
                string urgencyChoice;

                cout << "\n--- Issuing Delivery Command ---\n";
                cout << "Enter Package ID: ";
                cin >> packageID;

                cout << "Is this delivery urgent? (y/n): ";
                cin >> urgencyChoice;

                if (urgencyChoice == "y" || urgencyChoice == "Y")
                {
                    selectedVehicle->command("Deliver", packageID, "urgent");
                }
                else
                {
                    selectedVehicle->command("Deliver", packageID, "normal");
                }
            }
            else
            {
                cout << "\nError: No vehicle selected. Please select a vehicle first." << endl;
            }
            break;
        }

        case 7:
        {
            int vehicleChoice;
            cout << "\n--- Conflict Resolution ---\n";
            cout << "Select second vehicle for comparison:" << endl;
            cout << "1. RamzanDrone" << endl;
            cout << "2. RamzanTimeShip" << endl;
            cout << "3. RamzanHyperPod" << endl;
            cout << "Your choice: ";
            cin >> vehicleChoice;

            if (selectedVehicle)
            {
                switch (vehicleChoice)
                {
                case 1:
                    secondVehicle = &drone1;
                    break;
                case 2:
                    secondVehicle = &timeShip1;
                    break;
                case 3:
                    secondVehicle = &hyperPod1;
                    break;
                default:
                    cout << "Invalid vehicle choice." << endl;
                    secondVehicle = nullptr;
                }

                if (secondVehicle && selectedVehicle != secondVehicle)
                {
                    resolveConflict(*selectedVehicle, *secondVehicle);
                }
                else
                {
                    cout << "Cannot compare a vehicle with itself. Please select different vehicles." << endl;
                }
            }
            else
            {
                cout << "\nError: No primary vehicle selected. Please select a vehicle first." << endl;
            }
            break;
        }

        case 8:
            cout << "\nTotal deliveries tracked so far: " << drone1.getTrack() << endl;
            break;

        case 9:
            cout << "\nExiting RamzanBox Delivery System. Goodbye!" << endl;
            running = false;
            break;

        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }

        if (running)
        {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }

    return 0;
}