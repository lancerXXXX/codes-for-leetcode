#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A&&B)&&(check(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B));
    }
    bool check(TreeNode *A, TreeNode *B){
        if(!B) return true;
        if(!A||A->val!=B->val) return false;
        return check(A->left,B->left)&&check(A->right,B->right);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // // [1,2,3,4] [3]
    // TreeNode A(1);
    // TreeNode a2(2);
    // TreeNode a3(3);
    // TreeNode a4(4);
    // TreeNode B(3);
    // A.left=&a2;
    // A.right=&a3;
    // a2.left=&a4;

    
    // [4,2,3,4,5,6,7,8,9] [4,8,9]
    TreeNode A(4);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    TreeNode a5(5);
    TreeNode a6(6);
    TreeNode a7(7);
    TreeNode a8(8);
    TreeNode a9(9);
    TreeNode B(4);
    TreeNode b2(8);
    TreeNode b3(9);
    A.left=&a2;
    A.right=&a3;
    a2.left=&a4;
    a2.right=&a5;
    a3.left=&a6;
    a3.right=&a7;
    a4.left=&a8;
    a4.right=&a9;
    B.left=&b2;
    B.right=&b3;

    // //  [1,0,1,-4,-3] [1,-4]
    // TreeNode A(1);
    // TreeNode a2(0);
    // TreeNode a3(1);
    // TreeNode a4(-4);
    // TreeNode a5(-3);
    // TreeNode B(1);
    // TreeNode b2(-4);
    // A.left=&a2;
    // A.right=&a3;
    // a2.left=&a4;
    // a2.right=&a5;
    // B.left=&b2;

    cout<<s.isSubStructure(&A,&B);
    return 0;
}
