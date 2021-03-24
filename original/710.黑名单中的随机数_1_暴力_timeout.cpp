/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
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
class Solution {
private:
    int N;
    unordered_set<int> blacklist;
public:
    Solution(int N, vector<int>& blacklist) : N(N){
        this->blacklist = unordered_set<int> (blacklist.begin(), blacklist.end());
    }
    
    int pick() {
        int ans = rand() % N;
        while(blacklist.count(ans)) {
            ans = rand() % N;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

