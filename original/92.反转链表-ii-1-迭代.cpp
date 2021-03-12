// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem92.h"

using namespace std;
// @before-stub-for-debug-end

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
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pre = nullptr, * current = head, * new_back_pre = nullptr, * new_back = head;
        int index = 1;
        while (index <= right && current) {
            if (index < left) {
                new_back_pre = new_back;
                new_back = new_back->next;
            }
            ListNode* temp = current->next;
            if (index >= left && index <= right) {
                ListNode* temp = current->next;
                current->next = pre;
            }
            pre = current;
            current = temp;
            index++;
        }
        if (new_back_pre) new_back_pre->next = pre;
        else head = pre;
        new_back->next = current;
        return head;
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    int a[] = {};
    ListNode* head = new ListNode(1);
    ListNode* work = head;
    for (auto&& i : a)     {
        work->next = new ListNode(i);
        work = work->next;
    }
    Solution s;
    s.reverseBetween(head, 1, 1);
    return 0;
}
