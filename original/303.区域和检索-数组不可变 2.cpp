// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem303.h"

using namespace std;
// @before-stub-for-debug-end

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
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        for (auto &&i : nums)
            dp.push_back((dp.empty()? 0 : dp.back()) + i);
    }
    
    int sumRange(int i, int j) {
        return dp[j] - (i - 1 >= 0 ? dp[i - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

Accepted
16/16 cases passed (24 ms)
Your runtime beats 92.56 % of cpp submissions
Your memory usage beats 56.3 % of cpp submissions (16.8 MB)