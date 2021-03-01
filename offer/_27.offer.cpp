#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)
            return root;
        swap(root->left,root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};