#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>


using namespace std;
class Solution {
private:
    vector<int> res{ -1,-1 };
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        binarySearch(nums, target, 0, nums.size() - 1);
        return res;
    }
    void binarySearch(vector<int>& nums, int target, int b, int e) {
        if (b > e) return;
        int mid = (b + e) / 2;
        if (nums[mid] > target)
            binarySearch(nums, target, b, mid - 1);
        else if (nums[mid] < target)
            binarySearch(nums, target, mid + 1, e);
        else {
            res[0] = res[1] = mid;
            int l = mid - 1, r = mid + 1;
            for (;l >= b && nums[l] == target;l--)
                res[0] = l;
            for (;r <= e && nums[r] == target;r++)
                res[1] = r;
        }
    }
};

int main(int argc, char const* argv[]) {
    int a[] = { 1 };
    vector<int> va(a, a + 1);
    Solution s;
    va = s.searchRange(va, 1);
    cout << va[0] << "," << va[1] << endl;
    return 0;
}
