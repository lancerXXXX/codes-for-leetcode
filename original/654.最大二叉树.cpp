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
        return construct(nums, 0, nums.size() - 1);
    }
    TreeNode* construct(vector<int>& nums, int begin, int end) {
        if (begin > end) return nullptr;
        int piv = max_pos(nums, begin, end);
        TreeNode* root = new TreeNode(nums[piv]);
        root->left = construct(nums, begin, piv - 1);
        root->right = construct(nums, piv + 1, end);
        return root;
    }
    int max_pos(vector<int>& nums, int begin, int end) {
        int index = begin;
        for (int i = begin; i <= end; i++)
            if (nums[i] > nums[index])
                index = i;
        return index;
    }
};
// @lc code=end

Accepted
107/107 cases passed (92 ms)
Your runtime beats 92.27 % of cpp submissions
Your memory usage beats 74.26 % of cpp submissions (41.2 MB)
