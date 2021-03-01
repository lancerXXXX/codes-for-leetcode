/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
// 自底向上进行迭代
class Solution
{
public:
    int fib(int N)
    {
        if (N<2)
            return N;
        if (N==2)
            return 1;
        int fv1=0,fv2=1,temp=0;
        for(int index=2;index<=N;index++)
        {
            temp=(fv2+fv1)%(int)(1e9+7);
            fv1=fv2;
            fv2=temp;
        }
        return fv2;
    }
};
// @lc code=end
