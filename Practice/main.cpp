// Leetcode: Minimum XOR Path in a Grid
// https://leetcode.com/problems/minimum-xor-path-in-a-grid

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minCost(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<unordered_set<int>>> dp(rows, vector<unordered_set<int>>(cols));

    dp[0][0].insert(grid[0][0]);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (i == 0 && j == 0)
          continue;
        if (i > 0)
          for (int x : dp[i - 1][j])
            dp[i][j].insert(x ^ grid[i][j]);
        if (j > 0)
          for (int x : dp[i][j - 1])
            dp[i][j].insert(x ^ grid[i][j]);
      }
    }

    int ans = INT_MAX;
    for (auto i : dp[rows - 1][cols - 1])
      ans = min(ans, i);
    return ans;
  }
};

int main() {
  vector<vector<int>> grid = {{1, 2}, {3, 4}};
  Solution sol;
  cout << sol.minCost(grid) << endl;

  return 0;
}
