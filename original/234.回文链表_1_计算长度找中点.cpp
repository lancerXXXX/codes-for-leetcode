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
public:
    bool isPalindrome(ListNode* head) {
        ListNode* node_for_count = head;
        int length = 0;
        while (node_for_count) {
            length++;
            node_for_count = node_for_count->next;
        }
        int odd = length % 2 != 0;
        length = odd ? length / 2 : length / 2 - 1;
        ListNode* pre = nullptr, *current = head;
        for (; length >= 0; length--) {
            ListNode * temp = current->next;
            current->next = pre;
            pre = current;
            current = temp;
        }
        pre = odd ? pre->next : pre;
        while (current && current->val == pre->val) {
            pre = pre->next;
            current = current->next;
        }
        return !current;
    }
};
// @lc code=end


Accepted
84/84 cases passed (208 ms)
Your runtime beats 5.23 % of cpp submissions
Your memory usage beats 5.02 % of cpp submissions (107.5 MB)