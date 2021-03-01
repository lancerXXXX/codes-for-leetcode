#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        list<TreeNode*> l_p;
        list<TreeNode*> l_q;
        bool p_lock = false, q_lock = false;
        dfs (root, l_p, p_lock, p);
        dfs (root, l_q, q_lock, q);
        while (!l_p.size() && !l_q.size()) {
            if (l_p.front() == l_q.front())
                return l_q.front();
            l_p.pop_front();
            l_q.pop_front();
        }
        return nullptr;
    }
    void dfs(TreeNode* root, list<TreeNode*>& l, bool& lock, TreeNode* target) {
        cout << "dfs" << endl;
        if (!root) return;
        if (root->val == target->val) {
            lock = true; //加锁 -- 锁定目标序列
            return; //不在进行搜索
        }
        l.push_back(root);
        dfs(root->left, l, lock, target);
        if (!lock) {
            dfs(root->right, l, lock, target);
        }
        else
            return;
        if (!lock) {
            l.pop_back();
        }
        else {
            return;
        }
    }
};