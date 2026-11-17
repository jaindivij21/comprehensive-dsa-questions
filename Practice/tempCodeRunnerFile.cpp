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
      for (int j = 0; i + j < s.size(); j++) {
        temp += s[i + j] - '0';
      }
      s2 += to_string(temp);
    }

    return digitSum(s2, k);
  }
};