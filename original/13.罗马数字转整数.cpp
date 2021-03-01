// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem13.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
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
public:
    int romanToInt(string s) {
        pair<int, string> Roma_char[] = {
                                        make_pair(1000, "M"),
                                        make_pair(900, "CM"),
                                        make_pair(500, "D"),
                                        make_pair(400, "CD"),
                                        make_pair(100, "C"),
                                        make_pair(90, "XC"),
                                        make_pair(50, "L"),
                                        make_pair(40, "XL"),
                                        make_pair(10, "X"),
                                        make_pair(9, "IX"),
                                        make_pair(5, "V"),
                                        make_pair(4, "IV"),
                                        make_pair(1,"I") ,
        };
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            string s1 = s.substr(i, 1);
            string s2 = i + 1 < s.length() ? s.substr(i, 2) : "";
            for (auto&& p : Roma_char) {
                if (s2 == p.second) {
                    ans += p.first;
                    i++;
                    break;
                }
                if (s1 == p.second) {
                    ans += p.first;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

