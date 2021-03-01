#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int deepth = 0;
        queue<TreeNode *> q;
        if (!root)
            return 0;
        q.push(root);
        while (!q.empty())
        {
            int currentLevelSize = q.size();
            for (; currentLevelSize > 0; currentLevelSize--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            deepth++;
        }
        return deepth;
    }
};
// @lc code=end
