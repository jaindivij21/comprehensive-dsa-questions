// Leetcode: Calculate Digit Sum of a String
// https://leetcode.com/problems/calculate-digit-sum-of-a-string/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string digitSum(string s, int k) {
    // Base Case
    if (s.size() <= k)
      return s;

    // Recursive Cases
    string s2 = "";
    for (int i = 0; i < s.size(); i += k) {
      int temp = 0;
      for (int j = 0; j < k && i + j < s.size(); j++) {
        temp += (s[i + j] - '0');
      }
      s2 += to_string(temp);
    }

    return digitSum(s2, k);
  }
};

int main() {
  string s;
  int k;

  cin >> s >> k;

  Solution sol;
  cout << sol.digitSum(s, k) << endl;

  return 0;
}
