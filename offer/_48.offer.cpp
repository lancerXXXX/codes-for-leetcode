#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

class Solution {
private:
public:
    int lengthOfLongestSubstring(string s) {
        int max_count = 0;
        unordered_set<char> us;
        for (int p_left = 0, p_right = 0;p_left < s.length();p_left++) {
            for (;us.count(s[p_right]) == 0 && p_right < s.length();p_right++)
                us.insert(s[p_right]);
            max_count = max(max_count, p_right - p_left);
            us.erase(s[p_left]);
        }
        return max_count;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew");
    return 0;
}
