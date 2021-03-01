#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
// using namespace std;
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        while (root||!st.empty())
        {
            while (root)
            {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            ret.push_back(root->val);
            root=root->right;//如果有右孩子就去右孩子下一个while(root)一直往左走,如果没有右孩子->相当于赋值为空->跳过下一个循环的while(root)
        }
        return ret;
    }
};
// @lc code=end

