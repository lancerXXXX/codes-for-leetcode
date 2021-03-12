// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem98.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

 // @lc code=start
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTItem(root, nullptr, nullptr);
    }
    bool isValidBSTItem(TreeNode* root, TreeNode* min, TreeNode* max) {
        return !root ? true : ( ( !root->left ? true : ( root->left->val < root->val && ( !min ? true : (root->left->val > min->val)))) && ( !root->right ? true : ( root->right->val > root->val && ( !max ? true : (root->right->val < max->val)))) && isValidBSTItem(root->left, min, root) && isValidBSTItem(root->right, root, max));
    }
};
// @lc code=end

