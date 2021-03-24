// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem710.h"

using namespace std;
// @before-stub-for-debug-end

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

/**
 * 0 1 2 3
 * */

 // @lc code=start
class Solution {
private:
    int usableNum;
    unordered_map<int, int> mapping;
public:
    Solution(int N, vector<int>& blacklist) {
        usableNum = N - blacklist.size();
        for (auto&& index : blacklist) {
            mapping[index] = -1; // 记录所有需要被屏蔽的数字
        }
        int p_back = N - 1;
        for (auto&& index : blacklist) {
            if (index < usableNum) { // 如果 index 不在后边的屏蔽区, 需要交换
                while (mapping.count(p_back)) { // 寻找最后一个不需要屏蔽的
                    p_back--;
                }
                mapping[index] = p_back--; // 和 index 交换
            }
        }
    }

    int pick() {
        int ans = rand() % usableNum; // 可选数字在屏蔽区之前
        return mapping.count(ans) > 0 ? mapping[ans] : ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
 // @lc code=end

