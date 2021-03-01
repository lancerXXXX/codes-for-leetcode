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
    int singleNumber(vector<int>& nums) {
        int lows = 0, highs = 0;
        for (int num : nums) {
            lows = lows ^ num & ~highs;
            highs = highs ^ num & ~lows;
        }
        return lows;
    }
};
int main(int argc, char const* argv[]) {
    int a[] = { 3,3,3,1 };
    vector<int> va(a, a + 4);
    Solution s;
    s.singleNumber(va);
    return 0;
}