#include "TreeNode.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    if (k <= 0)
      return vector<int>();
    return work(arr, 0, arr.size() - 1, k);
  }
  vector<int> work(vector<int> &arr, int begin, int end, int k) {
    int piv = partition(arr, begin, end);
    if (piv + 1 == k)
      return vector<int>(arr.begin(), arr.begin() + k);
    else if (piv + 1 < k)
      return work(arr, piv + 1, arr.size() - 1, k);
    else
      return work(arr, begin, piv - 1, k);
  }
  int partition(vector<int> &arr, int begin, int end) {
    int piv = arr[begin];
    int latter = end, former = begin;
    while (latter > former) {
      while (latter > former && arr[latter] > piv)
        latter--;
      arr[former] = arr[latter];
      while (latter > former && arr[former] <= piv)
        former++;
      arr[latter] = arr[former];
    }
    arr[latter] = piv;
    return former;
  }
};

int main(int argc, char const *argv[]) {
  int a[10] = {0, 0, 1, 2, 4, 2, 2, 3, 1, 4};
  vector<int> va(a, a + 10);
  Solution s;
  s.getLeastNumbers(va, 8);
  return 0;
}
