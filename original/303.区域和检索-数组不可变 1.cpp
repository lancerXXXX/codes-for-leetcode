/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class NumArray {
private:
    vector<int> nums;
    map<pair<int, int>, int> cache;
public:
    NumArray(vector<int>& nums) : nums(nums) { }
    
    int sumRange(int i, int j) {
        if(cache.find(make_pair(i,j)) != cache.end()){
            return cache[make_pair(i,j)];
        }
        int sum = 0;
        for (; i <= j; i++)
            sum += nums[i];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

Accepted
16/16 cases passed (356 ms)
Your runtime beats 14.09 % of cpp submissions
Your memory usage beats 66.56 % of cpp submissions (16.7 MB)