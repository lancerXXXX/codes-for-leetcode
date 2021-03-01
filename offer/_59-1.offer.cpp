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

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
//         k--;
//         for (int front = 0; k < nums.size(); front++, k++)
//             result.push_back(maxK(nums, front, k));
//         return result;
//     }
//     int maxK(vector<int>& nums, int front, int k) {
//         int temp = nums[front];
//         for (size_t i = front + 1; i <= k; i++)
//             temp = max(nums[i], temp);
//         return temp;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        for (int front = -k + 1, back = 0; back < nums.size(); front++, back++){
            while (!dq.empty() && nums[back] > dq.back())
                dq.pop_back();
            dq.push_back(nums[back]);
            if (front >= 0){
                result.push_back(dq[0]);
                if (nums[front] == dq[0])
                    dq.pop_front();
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1,-1};
    vector<int> va(a,a+2);
    Solution s;
    s.maxSlidingWindow(va,1);
    return 0;
}
