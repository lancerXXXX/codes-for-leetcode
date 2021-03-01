#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        int p2 = 0, p3 = 0, p5 = 0;
        int ugly = 1;

        while (n > 1) {
            int temp_p2 = v[p2] * 2;
            int temp_p3 = v[p3] * 3;
            int temp_p5 = v[p5] * 5;
            ugly = min(min(temp_p2, temp_p3), temp_p5);
            v.push_back(ugly); n--;
            if (ugly == temp_p2) p2++;
            if (ugly == temp_p3) p3++;
            if (ugly == temp_p5) p5++;
        }
        return ugly;
    }
};


int main(int argc, char const* argv[]) {
    Solution s;
    cout << s.nthUglyNumber(10);
    return 0;
}
