#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> nums_temp(nums.size());
        return merge(nums, 0, nums.size() - 1, nums_temp);
    }
    int merge(vector<int>& nums, int begin, int end, vector<int>& nums_temp) {
        int count_reverse = 0;
        if (begin >= end) return 0;
        int mid = (begin + end) / 2;
        count_reverse += merge(nums, begin, mid, nums_temp);
        count_reverse += merge(nums, mid + 1, end, nums_temp);
        count_reverse += mergeItemAndcountReverse(nums, begin, mid + 1, end, nums_temp);
        return count_reverse;
    }
    int mergeItemAndcountReverse(vector<int>& nums, int first, int second, int end, vector<int>& nums_temp) {
        int count_reverse = 0, current = first, old_second = second, old_first = first;
        while (first < old_second && second <= end) {
            if (nums[first] <= nums[second])
                nums_temp[current++] = nums[first++];
            else {
                count_reverse += old_second - first;
                nums_temp[current++] = nums[second++];
            }
        }
        while (first < old_second) nums_temp[current++] = nums[first++];
        while (second <= end) nums_temp[current++] = nums[second++];
        copy(nums_temp.begin() + old_first, nums_temp.begin() + end+1, nums.begin() + old_first);
        return count_reverse;
    }
};

int main(int argc, char const* argv[]) {
    int a[] = { 7,5,6,4 };
    vector<int> va(a, a + 4);
    Solution s;
    cout << s.reversePairs(va) << endl;
    return 0;
}
