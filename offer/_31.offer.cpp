#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    int j = 0;
    for (int x : pushed) {
      s.push(x);
      for (; !s.empty() && s.top() == popped[j]; j++)
        s.pop();
    }
    return s.empty();
  }
};

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 3, 4, 5};
  vector<int> va(a, a + 5);
  int b[] = {4, 5, 3, 2, 1};
  vector<int> vb(b, b + 5);
  Solution s;
  s.validateStackSequences(va, vb);
  return 0;
}
