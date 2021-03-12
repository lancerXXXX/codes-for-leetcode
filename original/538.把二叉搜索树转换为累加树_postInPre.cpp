/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
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

215/215 cases passed (40 ms)
Your runtime beats 89.87 % of cpp submissions
Your memory usage beats 99.5 % of cpp submissions (32.4 MB)
