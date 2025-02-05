#include <iostream>
using namespace std;
class Calender
{
private:
    string months[12][31];
    int year;

public:
    Calender(int y)
    {
        year = y;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                months[i][j] = "";
            }
        }
    }
    void add_Task(int day, int mon, const string &task)
    {
        if (mon < 1 || mon > 12 || day < 1 || day > 32)
        {
            cout << "Invalid inputs :(" << endl;
            return;
        }
        months[mon - 1][day - 1] = task;
    }
    void remove_task(int day, int mon)
    {
        if (mon < 1 || mon > 12 || day < 1 || day > 31)
        {
            cout << "Invalid inputs :(" << endl;
            return;
        }
        months[mon - 1][day - 1] = "";
    }
    void show_task()
    {
        cout << "Tasks for the year " << year << " are" << endl;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                if (!months[i][j].empty())
                {
                    cout << "Month " << i + 1 << " ,Day " << j + 1 << " : " << months[i][j] << endl;
                }
            }
        }
    }
};
int main()
{
    Calender myCalendar(2025);

    myCalendar.add_Task(5, 1, "New Year Celebration");
    myCalendar.add_Task(14, 2, "Valentine's Day");
    myCalendar.add_Task(17, 3, "St. Patrick's Day");
    myCalendar.add_Task(4, 7, "Independence Day");
    myCalendar.add_Task(25, 12, "Kashmir Day");
    myCalendar.add_Task(31, 10, "Halloween");

    cout << "\nBefore removing a task:\n";
    myCalendar.show_task();

    myCalendar.remove_task(14, 2);

    cout << "\nAfter removing Valentine's Day task:\n";
    myCalendar.show_task();

    return 0;
}
