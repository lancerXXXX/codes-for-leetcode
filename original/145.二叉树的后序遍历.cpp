// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "TreeNode.h"
#include <stack>
// #include "commoncppproblem145.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
class Solution
{
private:
    stack<TreeNode *> st;

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;
        TreeNode *work = root, *r = nullptr; //work工作指针,r用来记录上一个被访问的结点
        while (work != nullptr || !st.empty())
        {
            while (work != nullptr)
            {
                st.emplace(work);
                work = work->left;
            }
            work = st.top();                                //弹出循环了,work=nullptr->栈顶元素没有左孩子
            if (work->right == nullptr || work->right == r) //如果有右孩子,并且没有被访问过(为什么=r就一定被访问过? 进行到 work有两种情况, 1. 我还在网下走 2. 我下边的访问完了->从右下往回走了 ↖ ->既然是右下,那么就是从右孩子回来的->r就是它的右孩子)
            {
                st.pop();//出栈访问
                result.emplace_back(work->val);
                r = work;//记录上一次访问的
                work = nullptr;//置为null->下一次循环跳过while->直接到赋值为栈顶
            }
            else //没有右孩子,或者右孩子刚刚被访问过了
                work = work->right;
        }
        return result;
    }
};
// @lc code=end
