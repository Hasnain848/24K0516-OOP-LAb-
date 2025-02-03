#include <iostream>
using namespace std;
int **Allocate_memory(int row, int colom);
void initializearray(int **arr, int row, int colom);
void sum(int **arr, int row, int colom);
void sum_each_row_colom(int **arr, int row, int colom);
void highest_row_colom(int **arr, int row, int colom);
void memoryfree(int **arr, int row);
int main()
{
    int row, colom;
    srand(time(0));
    cout << "Enter the row: ";
    cin >> row;
    cout << "Enter the coloum: ";
    cin >> colom;
    int **arr = Allocate_memory(row, colom);
    if (!arr)
    {
        cout << "Error in memory allocation" << endl;
        return 1;
    }
    initializearray(arr, row, colom);
    cout << "\nOriginal Matrix" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << "[";
        for (int j = 0; j < colom; j++)
        {
            cout << arr[i][j] << ",";
        }
        cout << "]\n";
    }
    sum(arr, row, colom);
    sum_each_row_colom(arr, row, colom);
    highest_row_colom(arr, row, colom);
    cout << "Transpose Matrix" << endl;
    for (int i = 0; i < colom; i++)
    {
        cout << "[";
        for (int j = 0; j < row; j++)
        {
            cout << arr[j][i] << ",";
        }
        cout << "]\n";
    }
    memoryfree(arr, row);
}
int **Allocate_memory(int row, int colom)
{
    int **arr = new int *[row];
    if (!arr)
    {
        cout << "Error in memory allocation" << endl;
        return nullptr;
    }
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[colom];
        if (!arr[i])
        {
            cout << "Error in memory allocation" << endl;
            for (int j = 0; j < i; j++)
                delete[] arr[j];
            delete[] arr;
            return nullptr;
        }
    }
    return arr;
}
void initializearray(int **arr, int row, int colom)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colom; j++)
        {
            arr[i][j] = rand() % 100 + 1;
        }
    }
}
void sum(int **arr, int row, int colom)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colom; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << "Sum: " << sum << endl;
}
void sum_each_row_colom(int **arr, int row, int colom)
{
    cout << "Row Sums: ";
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < colom; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << ",";
    }
    cout << "\nColumn Sums: ";
    for (int i = 0; i < colom; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << ",";
    }
}
void highest_row_colom(int **arr, int row, int colom)
{
    int *rowsum = new int[row];
    int max = 0, index;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < colom; j++)
        {
            sum += arr[i][j];
        }
        rowsum[i] = sum;
    }
    for (int i = 0; i < row; i++)
    {
        if (rowsum[i] > max)
        {
            max = rowsum[i];
            index = i;
        }
    }
    cout << "\nRow with highest Sum: Row " << index + 1 << endl;
    int *colsum = new int[colom];
    int max2 = 0, index2;
    for (int i = 0; i < colom; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        colsum[i] = sum;
    }
    for (int i = 0; i < colom; i++)
    {
        if (colsum[i] > max2)
        {
            max2 = colsum[i];
            index2 = i;
        }
    }
    cout << "Column with highest Sum: Column " << index2 + 1 << endl;
    delete[] rowsum;
    delete[] colsum;
}
void memoryfree(int **arr, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}