#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> vcr_result;
  vector<int> temp_result;
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    dfs(root, sum);
    return vcr_result;
  }
  void dfs(TreeNode *root, int target) {
    if (!root)
      return;
    temp_result.emplace_back(root->val);
    target -= root->val;
    dfs(root->left, target);
    dfs(root->right, target);
    if (!root->left && !root->right && 0 == target)
      vcr_result.emplace_back(temp_result);
    temp_result.pop_back();
  }
};

int main(int argc, char const *argv[]) { return 0; }
