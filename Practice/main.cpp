// Leetcode: Product of the Last K Numbers
// https://leetcode.com/problems/product-of-the-last-k-numbers

#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
public:
  vector<int> nums;

  ProductOfNumbers() {}

  void add(int num) {
    if (num == 0) {
      nums.clear();
      return;
    }

    if (nums.empty()) {
      nums.push_back(num);
      return;
    }

    int size = nums.size();
    nums.push_back(num * nums[size - 1]);
  }

  int getProduct(int k) {
    int size = nums.size();
    if (k > size)
      return 0;
    if (k == size)
      return nums[size - 1];
    return nums[size - 1] / nums[size - k - 1];
  }
};

int main() {
  ProductOfNumbers productOfNumbers;

  productOfNumbers.add(3);
  productOfNumbers.add(0);
  productOfNumbers.add(2);
  productOfNumbers.add(5);
  productOfNumbers.add(4);

  cout << productOfNumbers.getProduct(2) << endl; // 20
  cout << productOfNumbers.getProduct(3) << endl; // 40
  cout << productOfNumbers.getProduct(4) << endl; // 0

  productOfNumbers.add(8);

  cout << productOfNumbers.getProduct(2) << endl; // 32

  return 0;
}
