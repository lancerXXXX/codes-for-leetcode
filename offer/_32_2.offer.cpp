#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (!root)
      return result;
    int current_size = 1;
    queue<TreeNode *> q;
    q.push(root);
    result.push_back(vector<int>());
    while (!q.empty()) {
      if (current_size == 0) {//如果当前层 遍历完成, 重新设定 当前层数量
        current_size = q.size();
        result.push_back(vector<int>());
      }
      root = q.front(); q.pop();//取出队头处理
      current_size--; //当前层数量减少
      result.back().push_back(root->val);
      if (root->left)
        q.push(root->left);
      if (root->right)
        q.push(root->right);
    }
    return result;
  }
};
