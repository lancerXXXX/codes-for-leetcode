// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem215.h"

using namespace std;
// @before-stub-for-debug-end

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return QuickSort(nums, 0, nums.size()-1, nums.size()-k);
    }
    int QuickSort(vector<int> &nums, int low, int high, int k)
    {
        if (low < high)
        {
            int i=rand()%(high-low+1)+low;
            swap(nums[i],nums[low]);
            int pivot = Partition(nums, low, high);
            if (pivot == k)
                return nums[pivot];
            else if (pivot > k)
                return QuickSort(nums, low, pivot - 1, k);
            else
                return QuickSort(nums, pivot + 1, high, k);
        }
        else if (low==high)
            return nums[low];
        else 
            return -1;
    }
    int Partition(vector<int> &nums, int low, int high)
    {
        int temp = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= temp)
                high--;
            nums[low] = nums[high];
            while (low < high && nums[low] <= temp)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = temp;
        return low;
    }
};
// @lc code=end
