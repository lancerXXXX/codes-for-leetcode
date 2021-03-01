#include <shared_mutex>
#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val) {
        ListNode *work = head, *pre = head;
        if (head->val == val)
            return head->next;
        while (work) {
            if (work->val == val)
                pre->next = work->next;
            pre = work;
            work = work->next;
        }
        shared_ptr 
        return head;
    }
};