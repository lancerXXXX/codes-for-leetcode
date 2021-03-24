
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* last_unique = head; // 最后一个不重复元素
        ListNode* next_unique = head; // 当前遍历的元素
        while (next_unique) {
            if (next_unique->val == last_unique->val) { // 如果和最后一个不重复元素相同
                next_unique = next_unique->next; // 则跳过
            }else { // 如果出现不重复元素
                last_unique->next = next_unique; // 链接到下一个不重复元素
                last_unique = last_unique->next; // last_unique 位置更新
                next_unique = next_unique->next;
            }
        }
        last_unique->next = nullptr; // 链表跳过重复元素;
        return head;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> va{1,2,3,3};
    ListNode A(1);
    ListNode * a = &A;
    for (auto &&i : va)
    {
        a->next = new ListNode(i);
        a = a->next;
    }
    Solution s;
    s.deleteDuplicates(&A);
    return 0;
}


