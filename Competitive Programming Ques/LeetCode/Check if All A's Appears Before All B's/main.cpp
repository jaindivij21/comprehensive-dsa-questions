// Leetcode: Check if All A's Appears Before All B's
// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs

#include <iostream>
using namespace std;

class Solution {
public:
  bool checkString(string s) {
    bool b = false;
    for (auto i : s) {
      if (b && i == 'a')
        return false;

      if (i == 'b')
        b = true;
    }

    return true;
  }
};

int main() {
  string str = "aaabbb";

  Solution sol;
  cout << sol.checkString(str) << endl;
  return 0;
}
