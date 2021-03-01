#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "../TreeNode.h"
#include "../ListNode.h"


//[0,1,3,4,5,6,7,8,9]

//[0,1]
//[0,2]

using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>mid){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};