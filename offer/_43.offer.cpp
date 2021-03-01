#include "TreeNode.h"
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int countDigitOne(int n) {
    int result=0;
    int low = 0;
    int length = 0;
    int temp_n = n;
    int F_i_pre = 0;
    for (; temp_n != 0; ) { // 123  -- 3
      //从左向右 按位处理数字
      int cur = temp_n % 10;
      temp_n /= 10;

      //如果 i位数共会有多少个1
      length++;
      F_i_pre = 1 * pow(10, length-1) + 10 * F_i_pre;
      if(cur==0)
        cur=10;
      result+= ((cur-1)*F_i_pre);
      if(cur==1)
        result++;
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  s.countDigitOne(12);
  return 0;
}
