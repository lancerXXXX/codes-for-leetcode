// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

// #include "../TreeNode.h"
// #include "../ListNode.h"

using namespace std;

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* temp_left = lowestCommonAncestor(root->left, p, q);
        TreeNode* temp_right = lowestCommonAncestor(root->right, p, q);
        return (temp_left&&temp_right) ? root : (temp_left ? temp_left :temp_right);
    }
};
// @lc code=end
