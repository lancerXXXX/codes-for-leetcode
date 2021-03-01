#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <iomanip>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

// class Solution {
// public:
//     int lastRemaining(int n, int m) {
//         list<int> l(n);
//         iota(++l.begin(), l.end(), 1);
//         auto it = l.begin();
//         while (l.size() > 1) {
//             for (int i = 1; i < m; i++, it++)
//                 it = it == l.end() ? ++it : it;
//             it = it == l.end() ? ++it : it;
//             auto it_next = it;
//             it_next = ++it_next == l.end() ? ++it_next : it_next;
//             l.erase(it);
//             it = it_next;
//         }
//         return *it;
//     }
// };

// class Solution {
// public:
//     int lastRemaining(int n, int m) {
//         if (n == 1) return 0;
//         return (lastRemaining(n-1, m) + m) % n;
//     }
// };

class Solution {
public:
    int lastRemaining(int n, int m) {
        int last = 0;
        for (size_t i = 0; i < n; i++)
            last = (last + m) % (i + 1);
        return last;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    s.lastRemaining(5, 3);
    // for (size_t i = 0; i < 100; i++) {
    //     cout << setw(3) << (s.lastRemaining(i, 3) == 0 ? "\n" + to_string(i) + "\: " : "") << s.lastRemaining(i, 3);
    // }

    return 0;
}
