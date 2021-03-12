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
                if (left) {
                    TreeNode* min = work->right, * min_pre = min;
                    if (min) {
                        while (min->left) {
                            min_pre = min;
                            min = min->left;
                        }
                        if (min_pre == min) {
                            if (work == root)
                                root = min;
                            else
                                pre->left = min;
                            min->left = work->left;
                        }
                        else {
                            min_pre->left = min->right;
                            if (work == root)
                                root = min;
                            else
                                pre->left = min;
                            min->left = work->left;
                            min->right = work->right;
                        }
                        work->left = nullptr;
                        work->right = nullptr;
                    }
                    else {
                        if (work == root)
                            root = root->left;
                        else
                            pre->left = work->left;
                    }
                }
                else {
                    TreeNode* min = work->left, * min_pre = min;
                    if (min) {
                        while (min->right) {
                            min_pre = min;
                            min = min->right;
                        }
                        if (min_pre == min) {
                            if (work == root)
                                root = min;
                            else
                                pre->right = min;
                            min->right = work->right;
                        }
                        else {
                            min_pre->right = min->left;
                            if (work == root)
                                root = min;
                            else
                                pre->right = min;
                            min->right = work->right;
                            min->left = work->left;
                        }
                        work->right = nullptr;
                        work->left = nullptr;
                    }
                    else {
                        if (work == root)
                            root = root->left;
                        else
                            pre->right = work->right;
                    }
                }
                break;
            }
            pre = temp;
        }
        return root;
    }
};
// @lc code=end

