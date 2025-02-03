#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, i = 0;
    cout << "Enter the no of heights array you want: ";
    cin >> n;
    int j = n - 1;
    int *height = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Height " << i + 1 << " : ";
        cin >> height[i];
    }
    int area;
    int max = 0;
    while (i < j)
    {
        area = min(height[i], height[j]) * (j - i);
        if (area > max)
        {
            max = area;
        }
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    cout << "\n"<< max << endl;
    delete[] height;
}