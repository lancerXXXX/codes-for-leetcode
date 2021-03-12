/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

 // @lc code=start
 /*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* left;
     Node* right;
     Node* next;

     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

     Node(int _val, Node* _left, Node* _right, Node* _next)
         : val(_val), left(_left), right(_right), next(_next) {}
 };
 */

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        connectItem(root->left, root->right);
        return root;
    }
    void connectItem(Node* left, Node* right) {
        if (!left || !right) return;
        left->next = right;
        connectItem(left->left, left->right);
        connectItem(left->right, right->left);
        connectItem(right->left, right->right);
    }
};
// @lc code=end

Accepted
58/58 cases passed (28 ms)
Your runtime beats 50.81 % of cpp submissions
Your memory usage beats 95.85 % of cpp submissions (16.3 MB)

