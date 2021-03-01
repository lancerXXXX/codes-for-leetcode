#include "ListNode.h"
#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* pre=nullptr,*cur=head;
        while(cur){
            ListNode* temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
};

int main(int argc, char const *argv[])
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    l1.next=&l2;
    l2.next=&l3;
    l3.next=&l4;
    l4.next=nullptr;
    Solution s;
    s.reverseList(&l1);
    return 0;
}
