#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,bool> m;
        for (auto &&c : s)
            m[c]=(m.count(c)==0);
        for (auto &&c : s)
            if(m[c])
                return c;
        return ' ';
    }
};