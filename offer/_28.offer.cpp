#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isOrnot(root->left,root->right);
    }
    bool isOrnot(TreeNode* root_left,TreeNode* root_right){
        if(!root_left&&!root_right) return true;
        if(!root_left||!root_right) return false;
        if(root_left->val!=root_right->val)
            return false;
        return isOrnot(root_left->left,root_right->right)&&isOrnot(root_left->right,root_right->left);
    }
};

int main(int argc, char const *argv[])
{
        // [1,2,2,3,4,4,3]
    TreeNode A(1);
    TreeNode a2(2);
    TreeNode a3(2);
    TreeNode a4(3);
    TreeNode a5(4);
    TreeNode a6(4);
    TreeNode a7(3);
    A.left=&a2;
    A.right=&a3;
    a2.left=&a4;
    a2.right=&a5;
    a3.left=&a6;
    a3.right=&a7;
    Solution s;
    cout<<s.isSymmetric(&A);
    return 0;
}
