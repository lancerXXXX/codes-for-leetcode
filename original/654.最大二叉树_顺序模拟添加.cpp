// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem654.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        TreeNode* temp_root = new TreeNode(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            TreeNode* work = temp_root;
            if (work->val  > nums[i]) {
                TreeNode * pre = work;
                while (work && work -> val > nums[i]) {
                    pre = work;
                    work = work->right;
                }
                pre->right = new TreeNode(nums[i]);
                if(work) pre->right->left = work;
            }else{
                temp_root = new TreeNode(nums[i]);
                temp_root->left= work;
            }
        }
        return temp_root;
    }
};
// @lc code=end

Accepted
107/107 cases passed (92 ms)
Your runtime beats 92.27 % of cpp submissions
Your memory usage beats 98.91 % of cpp submissions (38.4 MB)
