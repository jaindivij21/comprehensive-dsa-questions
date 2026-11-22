// Leetcode: Find the Maximum Number of Elements in Subset
// https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumLength(vector<int> &nums) {
    unordered_map<long long, int> freq;
    for (int x : nums)
      freq[x]++;

    int ans = 1;
    if (freq.count(1)) {
      int c = freq[1];
      ans = max(ans, c % 2 ? c : c - 1);
    }

    for (auto &[x, count] : freq) {
      if (x == 1)
        continue;

      long long curr = x;
      int pairs = 0;
      while (curr <= LONG_MAX && freq.count(curr) && freq[curr] >= 2) {
        pairs++;
        curr = curr * curr;
      }

      int len;
      if (curr <= LONG_MAX && freq.count(curr))
        len = 2 * pairs + 1;
      else
        len = 2 * pairs - 1;

      ans = max(ans, len);
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {5, 4, 1, 2, 2};

  Solution sol;
  cout << sol.maximumLength(nums) << endl;
  return 0;
}
