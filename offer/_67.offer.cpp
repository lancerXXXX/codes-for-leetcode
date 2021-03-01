#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '+')
                return subFun(str.substr(i + 1), true);
            else if (str[i] == '-')
                return subFun(str.substr(i + 1), false);
            else if (str[i] >= '0' && str[i] <= '9')
                return subFun(str.substr(i), true);
            else if (str[i] == ' ');
            else
                break;
        }
        return 0;
    }
    int subFun(string str, bool flag) {
        if (str.length() == 0) return 0;
        long sum = 0;
        for (auto&& i : str) {
            if (i >= '0' && i <= '9') {
                if (flag) {
                    if (sum > (INT32_MAX - (i - '0')) / 10)
                        return INT32_MAX;
                    (sum *= 10) += (i - '0');
                }
                else {
                    if (sum > 0) sum = -sum;
                    if (sum < (INT32_MIN + (i - '0')) / 10)
                        return INT32_MIN;
                    (sum *= 10) -= (i - '0');
                }
            }
            else break;
        }
        return sum;
    }
};
