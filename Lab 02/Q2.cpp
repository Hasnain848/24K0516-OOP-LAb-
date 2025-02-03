#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of string array you want: ";
    cin >> n;
    cin.ignore();
    string *ptr = new string[n];
    int *ptr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "String " << i + 1 << " : ";
        getline(cin, *(ptr + i));
    }
    for (int i = 0; i < n; i++)
    {
        int m = ptr[i].length();
        cout << "\nReverse string " << i + 1 << " : ";
        for (int j = m; j >= 0; j--)
        {
            cout << ptr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int counter = 0;
        int n = ptr[i].length();
        for (int j = 0; j < n; j++)
        {

            if (ptr[i][j] == 'a' || ptr[i][j] == 'e' || ptr[i][j] == 'i' || ptr[i][j] == 'o' || ptr[i][j] == 'u')
                counter++;
            if (ptr[i][j] == 'A' || ptr[i][j] == 'E' || ptr[i][j] == 'I' || ptr[i][j] == 'O' || ptr[i][j] == 'U')
                counter++;
        }
        ptr2[i] = counter;
    }
    int max = 0, index;
    for (int i = 0; i < n; i++)
    {
        if (ptr2[i] > max)
        {
            max = ptr2[i];
            index = i;
        }
    }
    cout << "\nString that contain most vowels is" << endl;
    cout << "string: " << ptr[index];
    delete[] ptr;
    delete[] ptr2;
}