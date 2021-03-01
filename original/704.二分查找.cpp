#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return twoDividor(nums,0,nums.size()-1,target);
    }
    int twoDividor(vector<int> &nums,int begin,int end,int target){
        int mid=begin+((end-begin)>>1);
        if (begin>end)
            return -1;
        else if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
            return twoDividor(nums,begin,mid-1,target);
        else
            return twoDividor(nums,mid+1,end,target);
    }
};
// @lc code=end

