// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

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

// 1
//*1

// 1 2
//*1

 // 1 2 2 1
 // 1
 // 1*2 2

 // 1 2 3 3 2 1
 // 1
 // 1 2 3
 //   2*3   2

 // 1 2 3 2 1
 // 1
 // 1 2 3 
 //   2*3   1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* pre = nullptr, * current = head, * fast = head;
        for (; fast && fast->next && fast->next->next; ) {
            fast = fast->next->next;
            ListNode* temp = current->next;
            current->next = pre;
            pre = current;
            current = temp;
        }
        ListNode * temp = current->next;
        ListNode * fast_next = fast->next;
        current->next = pre;
        pre = temp;
        current = fast_next ? current :current->next;
        while (pre && pre->val == current->val) {
            pre = pre->next;
            current = current->next;
        }
        return !current;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    ListNode * A = new ListNode(1);
    ListNode * temp = A;
    int a[] = {2};
    for (auto &&i : a)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    Solution s; 
    s.isPalindrome(A);
    return 0;
}

Accepted
84/84 cases passed (224 ms)
Your runtime beats 5.23 % of cpp submissions
Your memory usage beats 5.02 % of cpp submissions (107.6 MB)