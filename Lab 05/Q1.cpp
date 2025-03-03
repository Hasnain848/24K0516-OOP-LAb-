#include<iostream>
using namespace std;
class Square{
    private:
    float sidelength;
    float area;
    static float allareas;
    public:
    Square():sidelength(0){}
    Square(float side):sidelength(side){}
    void Calculatearea(){
        area=sidelength*sidelength;
        allareas+=area;
    }
    float getsidelength(){ return sidelength; }
    void setsidelength(float side) { 
        sidelength = side;
       
    }    
  float getarea() const { return area; }
    void setarea(float a) { 
        area = a;
    }

    static float getallareas() { return allareas; }
    static void setallareas(float total) { allareas = total; }


};
float Square::allareas=0;
int main(){
    Square s1(5);
    Square s2(6);
    Square s3(7);
     cout << "Creating sq1 with side length 5:" << endl;
    s1.Calculatearea();
    cout << "Area of sq1: " << s1.getarea() << endl;
    cout << "Total area of all squares: " << Square::getallareas() << endl;

    cout << "\nCreating sq2 with side length 7:" << endl;
    s2.Calculatearea();
    cout << "Area of sq2: " << s2.getarea() << endl;
    cout << "Total area of all squares: " << Square::getallareas() << endl;

    cout << "\nCreating sq3 with side length 10:" << endl;
    s3.Calculatearea();
    cout << "Area of sq3: " << s3.getarea() << endl;
    cout << "Total area of all squares: " << Square::getallareas() << endl;

    return 0;

}