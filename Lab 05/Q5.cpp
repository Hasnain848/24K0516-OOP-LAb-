#include <iostream>
using namespace std;
class Engine
{
public:
    Engine()
    {
        cout << "Engine is created" << endl;
    }
    ~Engine()
    {
        cout << "Engine is detroyed" << endl;
    }
};
class Wheels
{
public:
    Wheels()
    {
        cout << "Wheels is created" << endl;
    }
    ~Wheels()
    {
        cout << "Wheels is detroyed" << endl;
    }
};
class Headlights
{
public:
    Headlights()
    {
        cout << "Headlights is created" << endl;
    }
    ~Headlights()
    {
        cout << "Headlights is detroyed" << endl;
    }
};
class Steering
{
public:
    Steering()
    {
        cout << "Steering is created" << endl;
    }
    ~Steering()
    {
        cout << "Steering is detroyed" << endl;
    }
};
class Car
{
    Engine *engine;
    Wheels wheels;
    Steering steering;
    Headlights *headlights;

public:
    Car() : engine(nullptr), headlights(nullptr) {}
    Car(Engine *e, Headlights *h, Steering st, Wheels w) : engine(e), headlights(h), steering(st), wheels(w)
    {
        cout << "Car created" << endl;
    }
    void installEngine(Engine *e)
    {
        engine = e;
        cout << "Engine is installed" << endl;
    }
    void installHeadlights(Headlights *h)
    {
        headlights = h;
        cout << "Headlights has been installed" << endl;
    }
    ~Car()
    {
        cout << "Car has been destroyed." << endl;
    }
};
int main()
{
    Engine e;
    Headlights h;
    Wheels w;
    Steering s;
    Car myCar(&e, &h, s, w);
    myCar.installEngine(&e);
    myCar.installHeadlights(&h);
    return 0;
}