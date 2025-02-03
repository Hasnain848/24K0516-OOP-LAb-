#include <iostream>
using namespace std;
int main()
{
    int n, target;

    cout << "Enter the number of elements in array: ";
    cin >> n;
    cout << "ENter the target : ";
    cin >> target;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << " :";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << "[" << i << "," << j << "] " << endl;
                cout << "nums[" << i << "] + nums[" << j << "] == " << target << endl;
            }
        }
    }
    delete[] arr;
}