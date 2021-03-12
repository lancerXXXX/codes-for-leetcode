// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */
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

/**
 * PostOrder
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
private:
    map<string, int> all_sequence;
    vector<TreeNode*> ans;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        PostOrder(root);
        return ans;
    }
    string PostOrder(TreeNode* root) {
        if (!root) return "#";
        string current = PostOrder(root->left) + " " + PostOrder(root->right) + " " + to_string(root->val);
        if (all_sequence[current] == 1)
            ans.push_back(root);
        all_sequence[current]++;
        return current;
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    TreeNode A(1);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    TreeNode a5(2);
    TreeNode a6(4);
    TreeNode a7(4);
    A.left = &a2;
    A.right = &a3;
    a2.left = &a4;
    a3.left = &a5;
    a3.right = &a6;
    a5.left = &a7;
    Solution s;
    s.findDuplicateSubtrees(&A);
    return 0;
}

175/175 cases passed (52 ms)
Your runtime beats 63.71 % of cpp submissions
Your memory usage beats 82.97 % of cpp submissions (38.6 MB)