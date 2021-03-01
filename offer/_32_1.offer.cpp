#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> levelOrder(TreeNode *root) {
    vector<int> result;
    if (!root)
      return result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      root=q.front();
      q.pop();
      result.push_back(root->val);
      if (root->left)
        q.push(root->left);
      if (root->right)
        q.push(root->right);
    }
    return result;
  }
};