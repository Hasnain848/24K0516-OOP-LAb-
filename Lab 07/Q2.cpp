#include <iostream>
#include <cmath>
using namespace std;
class Shape
{
protected:
    int posx, posy;
    string color;
    int boarderthickness;

public:
    Shape(int posx, int posy, string color, int thick) : posx(posx), posy(posy), color(color), boarderthickness(thick) {}
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};
class Circle : public Shape
{
    int radius;
    string centeredposition;

public:
    Circle(int posx, int posy, string color, int thick, int radius, string centeredpos) : Shape(posx, posy, color, thick), radius(radius), centeredposition(centeredpos) {}

    void draw() override
    {
        cout << "Drawing Circle at position (" << posx << "," << posy << ") with radius " << radius << " ,colour " << color << " ,and Boarderthickness " << boarderthickness << endl;
    }
    double calculateArea() override
    {
        return 3.14159 * radius * radius;
    }
    double calculatePerimeter() override
    {
        return 2 * 3.14159 * radius;
    }
};
class Rectangle : public Shape
{
    int width, height;
    string cornerpo;

public:
    Rectangle(int posx, int posy, string color, int thick, int width, int height, string cornerpo) : Shape(posx, posy, color, thick), width(width), height(height), cornerpo(cornerpo) {}

    void draw() override
    {
        cout << "Drawing Rectangle at position (" << posx << "," << posy << ") with Height " << height << " , width " << width << ",colour " << color << " ,and Boarderthickness " << boarderthickness << endl;
    }
    double calculateArea() override
    {
        return width * height;
    }
    double calculatePerimeter() override
    {
        return 2 * (width + height);
    }
};
class Triangle : public Shape
{
    int a, b, c;

public:
    Triangle(int posx, int posy, string color, int thick, int a, int b, int c) : Shape(posx, posy, color, thick), a(a), b(b), c(c) {}
    void draw() override
    {
        cout << "Drawing Triangle at position (" << posx << "," << posy << ") with sides: a= " << a << ",b= " << b << ",c= " << c << ",colour " << color << " ,and Boarderthickness " << boarderthickness << endl;
    }
    double calculateArea() override
    {
        double s;
        s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double calculatePerimeter() override
    {
        return a + b + c;
    }
};
class Polygon : public Shape
{
    int numofsides;
    int *sidelen;

public:
    Polygon(int posx, int posy, string color, int thick, int numsides, int *s) : Shape(posx, posy, color, thick), numofsides(numsides)
    {
        sidelen = new int[numofsides];
        for (int i = 0; i < numofsides; i++)
            sidelen[i] = s[i];
    }
    void draw() override
    {
        cout << "Drawing Polygon at position (" << posx << "," << posy << ") with sides: ";
        for (int i = 0; i < numofsides; i++)
        {
            cout << sidelen[i] << " ";
        }
        cout << " colour " << color << " ,and Boarderthickness " << boarderthickness << endl;
    }
    double calculateArea() override
    {
        if (numofsides < 3)
            return 0; // ------Assuming are for Regular polygon-------

        double s = sidelen[0];
        return (numofsides * s * s) / (4 * tan(M_PI / numofsides));
    }
    double calculatePerimeter() override
    {
        double perimeter = 0;
        for (int i = 0; i < numofsides; i++)
        {
            perimeter += sidelen[i];
        }
        return perimeter;
    }
    ~Polygon()
    {
        delete[] sidelen;
    }
};
int main()
{
    Circle c(5, 5, "Red", 2, 10, "Center");
    c.draw();
    cout << "Circle Area: " << c.calculateArea() << endl;
    cout << "Circle Perimeter: " << c.calculatePerimeter() << endl;

    Rectangle r(2, 3, "Blue", 3, 4, 5, "Top-Left");
    r.draw();
    cout << "Rectangle Area: " << r.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << endl;

    Triangle t(1, 1, "Green", 1, 3, 4, 5);
    t.draw();
    cout << "Triangle Area: " << t.calculateArea() << endl;
    cout << "Triangle Perimeter: " << t.calculatePerimeter() << endl;

    int sides[] = {5, 5, 5, 5, 5}; // ------------as we assume Regular Pentagon-----------------
    Polygon p(0, 0, "Yellow", 2, 5, sides);
    p.draw();
    cout << "Polygon Area: " << p.calculateArea() << endl;
    cout << "Polygon Perimeter: " << p.calculatePerimeter() << endl;

    return 0;
}