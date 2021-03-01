/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,piv=0;
        while(low<=high){
            piv=(low+high)/2;
            if(target==nums[piv])//找到目标
                return piv;
            if(nums[low]>nums[piv])//左无序,右有序
                if(target>=nums[piv]&&target<=nums[high])//如果处于右有序最大最小值之间
                    low=piv+1;//进入右边
                else
                    high=piv-1;//否则 去左边
            else if(nums[high]<nums[piv])//左有序,右无序
                if(target>=nums[low]&&target<=nums[piv])//如果处于左有序最大最小值之间
                    high=piv-1;//进入左边
                else
                    low=piv+1;//否则 去右边
            else//左有序,右有序->进行正常二分
                if(target>nums[piv])
                    low=piv+1;
                else
                    high=piv-1;
        }
        return -1;
    }
};
// @lc code=end

