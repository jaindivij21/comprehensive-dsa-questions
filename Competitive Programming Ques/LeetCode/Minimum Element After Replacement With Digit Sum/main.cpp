// Leetcode: Minimum Element After Replacement With Digit Sum
// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    int sumOfDigits(int x)
    {
        int sum = 0;
        while (x != 0)
        {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums)
    {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            ans = min(ans, sumOfDigits(nums[i]));

        return ans;
    }
};

int main()
{
    vector<int> nums = {10, 12, 13, 14};
    Solution sol;
    cout << sol.minElement(nums) << endl;

    return 0;
}
