// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem75.h"

using namespace std;
// @before-stub-for-debug-end

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int index = 0,high=nums.size()-1,low=0;
        while (index<=high)
        {
            //情况一:如果是nums[index]=0,交换,换过来的是什么--
                // 由于index之前的已经处理完了
                    //那么只可能是三种情况
                        //1. index=low=0
                        //2. index=low -> 00...low=index
                        //3. index>low -> 00...low 1...index
                    //所以换过来的只可能是1或者自己和自己换
            //情况二:如果是nums[index]=2,交换
                //由于后面的还没有处理
                    //换过来的可能是 0,1,2
                    //如果是0,1->像情况一一样处理
                    //如果是2->重复处理2
            //index当前有两种可能的情况
                //情况一->只需要处理一边
                //情况二->需要循环 并且 可能再次产生 情况一
                //所以先处理完情况二 -> 再处理情况一
            while(index<=high&&nums[index]==2){
                swap(nums[index],nums[high]);
                high--;
            }
            if (nums[index]==0){
                swap(nums[index],nums[low]);
                low++;
            }
            index++;
        }
    }
};
// @lc code=end
