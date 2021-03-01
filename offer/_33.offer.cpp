#include "TreeNode.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
// class Solution {
// public:
//   bool verifyPostorder(vector<int> &postorder) {
//     vector<int> inorder = postorder;
//     sort(inorder.begin(), inorder.end());
//     int count = postorder.size() - 1;
//     return calculate(inorder, postorder, 0, inorder.size() - 1, 0,
//                      postorder.size() - 1);
//   }
//   bool calculate(vector<int> &inorder, vector<int> &postorder, int in_begin,
//                  int in_end, int post_begin, int post_end) {
//     if (in_begin > in_end) {
//       return true;
//     }
//     int root_val = postorder[post_end]; //后序最后一个试 根
//     int in_root = -1;                   //找 根 在中序中的位置
//     for (int i = in_begin; i <= in_end; i++) {
//       if (inorder[i] == root_val) {
//         in_root = i;
//         break;
//       }
//     }
//     if (in_root == -1)
//       return false;
//     int left_length = in_root - in_begin;
//     return calculate(inorder, postorder, in_begin, in_root - 1, post_begin,
//                      post_begin + left_length - 1) &&
//            calculate(inorder, postorder, in_root + 1, in_end,
//                      post_begin + left_length, post_end - 1);
//   }
// };

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
      return calculate(postorder,0,postorder.size()-1);
    }
    bool calculate(vector<int>& postorder,int begin,int end){
      int left_bound=begin,right_bound=end;
      int root_val=postorder[end];
      while(left_bound<=end&&postorder[left_bound]<root_val)
        left_bound++;
      while(right_bound>=begin&&postorder[right_bound]>=root_val)
        right_bound--;
      if(left_bound-right_bound==1){
        return calculate(postorder,begin,left_bound-1)&&calculate(postorder,right_bound+1,end);
      }
      else{
        return false;
      }
    }
};

int main(int argc, char const *argv[]) {
  int a[7] = {4, 8, 6, 12, 16, 14, 10};
  vector<int> va(a, a + 7);
  Solution s;
  s.verifyPostorder(va);
  return 0;
}
