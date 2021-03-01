#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

// class Solution {
// private:
//     map<int, double> m;
//     int sum_all = 0;
// public:
//     vector<double> dicesProbability(int n) {
//         vector<double> res;
//         int sum = 0;
//         count(sum, n);
//         for (auto&& i : m)
//             res.push_back(i.second /= sum_all);
//         return res;
//     }
//     void count(int& sum, int& n) {
//         if (n == 0) {
//             m[sum] = m.count(sum) > 0 ? m[sum] + 1 : 1;
//             sum_all += 1;
//             return;
//         }
//         for (int i = 1; i < 7; sum -= i, n += 1, i++)
//             count(sum += i, n -= 1);
//     }
// };

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> dp(n, vector<int>(n * 6, 0));

        for (size_t i = 0; i < 6; i++)
            dp[0][i] = 1;
        for (size_t deep = 1; deep < n; deep++)
            for (size_t num = deep; num < (deep + 1) * 6; num++)
                for (size_t step = 1; step <= num - deep + 1 && step <= 6; step++)
                    dp[deep][num] += dp[deep - 1][num - step];
        vector<double> res(dp.back().begin() + n - 1, dp.back().end());
        double sum = accumulate(res.begin(), res.end(), 0);
        for (size_t i = 0; i < res.size(); i++)
            res[i] /= sum;
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    s.dicesProbability(2);
    return 0;
}
