// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem450.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        bool left = true;
        TreeNode* work = root, * pre = root;
        while (work) {
            TreeNode* temp = work;
            if (work->val > key) {
                work = work->left;
                left = true;
            }
            else if (work->val < key) {
                work = work->right;
                left = false;
            }
            else {
                TreeNode* min = work->right, * min_pre = min;
                if (min) {
                    while (min->left) {
                        min_pre = min;
                        min = min->left;
                    }
                    min->left = work->left;
                    if (min_pre!= min){
                        min_pre->left = min->right;
                        min->right = work->right;
                    }
                }
                if (work == root)
                    root = min ? min : work->left;
                else {
                    if (left) pre->left = min ? min : work->left;
                    else pre->right = min ? min : work->left;
                }
                work->left = work->right = nullptr;
                break;
            }
            pre = temp;
        }
        return root;
    }
};
// @lc code=end

Accepted
91/91 cases passed (40 ms)
Your runtime beats 84.37 % of cpp submissions
Your memory usage beats 68.27 % of cpp submissions (31.9 MB)
