#include <iostream>
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int sum=0;
        while (x!=0)
        {
            int temp=x%10;
            x/=10;
            if(INT_MAX/10<sum||INT_MAX/10==sum&&temp>7) return 0;
            if(INT_MIN/10>sum||INT_MIN/10==sum&&temp<-8) return 0;
            sum=sum*10+temp;
        }
        return sum;
    }
};
// @lc code=end

