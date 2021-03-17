// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem739.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

 // @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> ans(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            while (!s.empty() && T[i] > T[s.top()]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end

