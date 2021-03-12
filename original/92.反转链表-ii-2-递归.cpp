/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* back = nullptr;
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reversePreN(head, right);
        }
        else {
            head->next = reverseBetween(head->next, left - 1, right - 1);
        }
        return head;
    }
    ListNode* reversePreN(ListNode* head, int right) {
        if (right == 1) {
            back = head->next;
            return head;
        }
        ListNode* new_head = reversePreN(head->next, right - 1);
        head->next->next = head;
        head->next = back;
        return new_head;
    }
};
// @lc code=end

