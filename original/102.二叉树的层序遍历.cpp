#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        queue<TreeNode *> qu;
        if (!root)
            return ret;
        qu.push(root);
        while (!qu.empty())
        {
            vector<int> tempInt;
            int currentLevelSize = qu.size(); //一层一层往里放,上一层每个结点的孩子挨个往里放,放完孩子就走了,到下一轮,qu就剩下上一层的孩子
            for (; currentLevelSize > 0; currentLevelSize--)
            {
                auto work = qu.front();
                qu.pop();//访问
                tempInt.push_back(work->val);//放入该层数组
                if (work->left)//左右孩子压栈
                    qu.push(work->left);
                if (work->right)
                    qu.push(work->right);
            }
            ret.push_back(tempInt);
        }
        return ret;
    }
};
// @lc code=end
