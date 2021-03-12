/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 把二叉搜索树转换为累加树
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
private:
    int count = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        PostInPre(root);
        return root;
    }
    void PostInPre(TreeNode* root) {
        if(!root) return;
        PostInPre(root->right);
        root->val = (count += root->val);
        PostInPre(root->left);
    }
};
// @lc code=end

28/28 cases passed (4 ms)
Your runtime beats 53.99 % of cpp submissions
Your memory usage beats 79.09 % of cpp submissions (7.9 MB)
