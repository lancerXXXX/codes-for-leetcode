#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return isBalanced(root->left)&&isBalanced(root->right)&&(abs(treeHeight(root->left)-treeHeight(root->right))<2);
    }
    int treeHeight(TreeNode* root){
        if(!root) return 0;
        return max(treeHeight(root->left),treeHeight(root->right))+1;
    }
};