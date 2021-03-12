// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem25.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// #include "../TreeNode.h"
// #include "../ListNode.h"


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre = nullptr, * current = head, * work = head;
        int count = 0;
        while (work && count < k) {
            work = work->next;
            count++;
        }
        if (count == k) {
            for (int i = 0; i < k && current != nullptr; i++) {
                ListNode* temp = current->next;
                current->next = pre;
                pre = current;
                current = temp;
            }
            head->next = reverseKGroup(current, k);
            return pre;
        }
        else {
            return head;
        }
    }
};
// @lc code=end

Accepted
62/62 cases passed (20 ms)
Your runtime beats 79.06 % of cpp submissions
Your memory usage beats 62.58 % of cpp submissions (11.2 MB)
