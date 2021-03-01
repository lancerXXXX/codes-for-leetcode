#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current_majority=INT_MAX;
        int current_majority_num=0;
        for ( int current : nums){
            if(current_majority_num==0)
                current_majority=current;
            if(current==current_majority)
                current_majority_num++;
            else
                current_majority_num--;
        }
        return current_majority;
    }
};