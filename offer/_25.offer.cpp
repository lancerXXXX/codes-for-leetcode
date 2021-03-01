#include "ListNode.h"
#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head_pre=new ListNode(-1),*work=head_pre;
        while(l1&&l2){
            if(l1->val<=l2->val){
                work->next=l1;
                l1=l1->next;
            }else{
                work->next=l2;
                l2=l2->next;
            }
            work=work->next;
        }
        work->next=l1?l1:l2;
        return head_pre->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(4);
    l1.next=&l2;
    l2.next=&l3;
    l3.next=nullptr;
    ListNode j1(1);
    ListNode j2(3);
    ListNode j3(4);
    j1.next=&j2;
    j2.next=&j3;
    j3.next=nullptr;
    s.mergeTwoLists(&l1,&j1);
    return 0;
}
