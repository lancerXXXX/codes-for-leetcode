#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

// class Solution {
// public:
//     vector<int> constructArr(vector<int>& a) {
//         int length = a.size();
//         vector<int> ans;
//         if (length == 0) return ans;
//         vector<int> pre{ 1 };
//         vector<int> back{ 1 };
//         for (int i = 0, j = length - 1; i < length - 1; i++, j--) {
//             pre.push_back(pre[i] * a[i]);
//             back.push_back(back[i] * a[j]);
//         }
//         for (int i = 0; i < length; i++) 
//             ans.push_back(pre[i] * back[length - 1 - i]);
//         return ans;
//     }
// };

// class Solution {
// private:
//     vector<int> ans;
// public:
//     vector<int> constructArr(vector<int>& a) {
//         calculate(a, 1, 0);
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
//     int calculate(vector<int>& a, int sum_pre, int index) {
//         if (index == a.size())
//             return 1;
//         int back = calculate(a, sum_pre * a[index], index + 1);
//         ans.push_back(sum_pre * back);
//         return a[index] * back;
//     }
// };


class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int length = a.size();
        if (length == 0) return vector<int>();
        vector<int> ans(length);
        for (int pre_sum = 1, i = 0; i < length; pre_sum *= a[i], i++)
            ans[i] = pre_sum;
        for (int back_sum = 1, i = length - 1; i >= 0; back_sum *= a[i], i--)
            ans[i] *= back_sum;
        return ans;
    }
};


int main(int argc, char const* argv[]) {
    vector<int> va{ 1, 2 ,3 ,4 , 5 };
    Solution s;
    cout << s.constructArr(va)[0] << endl;
    return 0;
}
