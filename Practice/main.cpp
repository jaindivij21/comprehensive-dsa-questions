// Leetcode: Minimum Cost of Buying Candies With Discount
// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    int minimumCost(vector<int>& cost)
    {
        sort(cost.begin(), cost.end());

        int minCost = 0;
        int itr = cost.size() - 1;
        int cnt = 0;
        while (itr >= 0)
        {
            if (cnt == 2)
            {
                cnt = 0;
                itr--;
                continue;
            }
            minCost += cost[itr];
            cnt++;
            itr--;
        }

        return minCost;
    }
};

int main()
{
    vector<int> cost = {1, 2, 3};
    Solution sol;
    cout << sol.minimumCost(cost) << endl;

    return 0;
}
