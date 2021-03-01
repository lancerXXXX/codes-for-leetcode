#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "TreeNode.h"
#include "ListNode.h"


using namespace std;
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* workA = headA, * workB = headB;
        while (workB!=workA){
            workA=!workA?headB:workA->next;
            workB=!workB?headA:workB->next;
        }
        return workA;
    }
};