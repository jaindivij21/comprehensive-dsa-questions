// Leetcode: Create Grid With Exactly One Path
// https://leetcode.com/problems/create-grid-with-exactly-one-path

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    vector<string> createGrid(int m, int n)
    {
        vector<string> ans;

        string topRow = "";
        for (int i = 0; i < n; i++) topRow += '.';
        ans.push_back(topRow);

        string otherRows = "";
        for (int i = 0; i < n; i++)
            i == n - 1 ? otherRows += '.' : otherRows += '#';

        for (int i = 0; i < m - 1; i++) ans.push_back(otherRows);

        return ans;
    }
};

int main()
{
    int m = 2, n = 3;
    Solution sol;
    vector<string> ans = sol.createGrid(m, n);

    for (auto i : ans) cout << i << " ";

    return 0;
}
