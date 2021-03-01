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
private:
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int front = 0, back = nums.size() - 1;
        while (front < back) {
            int sum = nums[front] + nums[back];
            if (sum == target)
                return vector<int> {nums[front], nums[back]};
            else if (sum > target)
                back--;
            else
                front++;
        }
        return vector<int> {-1, -1};
    }
};

int main(int argc, char const* argv[]) {
    int a[] = { 2,7,11,15 };
    vector<int> va(a, a + 4);
    Solution s;
    s.twoSum(va, 9);
    return 0;
}
