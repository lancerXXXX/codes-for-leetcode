#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        int level=0;
        deque<TreeNode *> q;
        q.push_back(root);
        while(!q.empty()){
            int count=q.size();
            result.push_back(vector<int> ());
            for(;count>0;count--){ 
                if(level%2==0){
                    root=q.front();
                    q.pop_front();
                    if(root->left)
                        q.push_back(root->left);
                    if(root->right)
                        q.push_back(root->right);
                }else{
                    root=q.back();
                    q.pop_back();
                    if(root->right)
                        q.push_front(root->right);
                    if(root->left)
                        q.push_front(root->left);
                }
                result.back().push_back(root->val);
            }
            level++;
        }
        return result; }
};