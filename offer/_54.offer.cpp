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
private:
    int res = 0;
public:
    int kthLargest(TreeNode* root, int k) {
        ReversePostOrder(root, k);
        return res;
    }
    void ReversePostOrder(TreeNode* root, int& k) {
        if (!root) return;
        ReversePostOrder(root->right, k);
        if (k == 1) res = root->val;
        k--;
        ReversePostOrder(root->left, k);
    }
};

int main(int argc, char const* argv[]) {
    TreeNode A(1);
    TreeNode a3(2);
    A.right = &a3;
    Solution s;
    cout<<s.kthLargest(&A,2);
    return 0;
}