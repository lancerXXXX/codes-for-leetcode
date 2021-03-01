#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "TreeNode.h"
using namespace std;

class MinStack {
private:
  stack<int> s;
  stack<int> min_s;

public:
  /** initialize your data structure here. */
  MinStack() { min_s.push(INT_MAX); };

  void push(int x) {
    s.push(x);
    min_s.push(std::min(x, min_s.top()));
  }

  void pop() {
    s.pop();
    min_s.pop();
  }

  int top() {
    return s.top();
  }

  int min() {
    return min_s.top();
  }
};

int main(int argc, char const *argv[]) {
  MinStack s;
  s.push(1);
  s.push(2);
  s.push(3);
  cout << s.min() << endl;
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  return 0;
}
