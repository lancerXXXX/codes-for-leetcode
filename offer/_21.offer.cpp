#include "ListNode.h"
#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* pre=head,* lat=head;
        while(k>0){
            lat=lat->next;
            k--;
        }
        while(lat!=nullptr){
            lat=lat->next;
            pre=pre->next;
        }
        return pre;
    }
};