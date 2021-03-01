#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        stack<Node *> s;
        Node* pre=nullptr;
        Node* head=nullptr;
        bool flag=true;
        while(root||!s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top(); s.pop();
            if(flag){
                head=root;
                flag=false;
            }
            if(pre){
                pre->right=root;
                root->left=pre;
            }
            pre=root;
            root=root->right;
        }
        head->left=pre;
        pre->right=head;
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Node a1(1);
    Node a2(2);
    Node a3(3);
    Node a4(4);
    Node a5(5);
    a4.left=&a2;
    a4.right=&a5;
    a2.left=&a1;
    a2.right=&a3;
    Solution s;
    s.treeToDoublyList(&a4);
    return 0;
}
