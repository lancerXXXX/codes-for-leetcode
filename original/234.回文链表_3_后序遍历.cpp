/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* pre;
public:
    bool isPalindrome(ListNode* head) {
        pre = head;
        return postOrder(head);
    }
    bool postOrder(ListNode* current) {
        if (!current) return true;
        bool ans_post = postOrder(current->next);
        bool ans = current->val== pre->val;
        pre = pre->next;
        return ans && ans_post;
    }
};
// @lc code=end

Accepted
84/84 cases passed (248 ms)
Your runtime beats 5.23 % of cpp submissions
Your memory usage beats 5.02 % of cpp submissions (118.1 MB)
