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
        if (root->val == key) {
            TreeNode* right_max = root->right, *right_max_pre = nullptr;
            while (right_max && right_max->left){
                right_max_pre = right_max;
                right_max = right_max->left;
            }
            if (!right_max) {
                root = root->left;
            }
            else if (right_max == root->right) {
                right_max->left= root->left;
                root = right_max;
            }
            else {
                right_max_pre->left= right_max->right;
                right_max->right= root->right;
                right_max->left= root->left;
                root = right_max;
            }
        }
        else {
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            }else{
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};
// @lc code=end

