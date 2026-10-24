// Leetcode: Count Days Spent Together
// https://leetcode.com/problems/count-days-spent-together

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
   private:
    vector<int> daysOfTheMonth = {31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31};

   public:
    int getDaysOfTheMonth(int monthIndex)
    {
        if (monthIndex >= 12 || monthIndex < 0) return -1;
        return daysOfTheMonth[monthIndex];
    }

    int dayOfTheYear(string date)
    {
        int monthNumber = stoi(date.substr(0, 2));
        int dateNumber = stoi(date.substr(3, 2));

        int dayOfTheYear = 0;
        for (int i = 0; i < monthNumber - 1; i++)
            dayOfTheYear += getDaysOfTheMonth(i);

        return dayOfTheYear + dateNumber;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob)
    {
        int aArrive = dayOfTheYear(arriveAlice);
        int aLeave = dayOfTheYear(leaveAlice);
        int bArrive = dayOfTheYear(arriveBob);
        int bLeave = dayOfTheYear(leaveBob);

        int start = max(aArrive, bArrive);
        int end = min(aLeave, bLeave);

        return max(0, end - start + 1);
    }
};

int main()
{
    Solution sol;
    string arriveAlice = "08-15";
    string leaveAlice = "08-18";
    string arriveBob = "08-16";
    string leaveBob = "08-19";

    cout << sol.countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob)
         << endl;

    return 0;
}
