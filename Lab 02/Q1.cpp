#include <iostream>
using namespace std;
int main()
{

 int n, index;
 float sum = 0.0, average;
 cout << "Enter the number of elements in array you want: ";
 cin >> n;
 float *ptr = new float[n];
 for (int i = 0; i < n; i++)
 {
  cout << "Enter element " << i + 1 << " : ";
  cin >> *(ptr + i);
  sum += ptr[i];
 }
 average = sum / n;
 float a1, diff = 100.0;
 for (int i = 0; i < n; i++)
 {
  a1 = average - ptr[i];
  if (a1 < 0)
   a1 = a1 * (-1);
  if (a1 < diff)
  {
   diff = a1;
   index = i;
  }
 }
 cout << "\nAverage: " << average << endl;
 cout << "Closest Number: " << ptr[index];
}