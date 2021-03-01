#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> vs;
        for(int num:nums) vs.push_back(to_string(num));
        sort(vs.begin(),vs.end(),cmp);
        string result = "";
        for(string s:vs) result+=s;
        return result;
    }
    static bool cmp(const string& first,const string &second){
        return first+second<second+first;
    }
};
int main(int argc, char const* argv[]) {
    int a[] = {1,2,3,1};
    vector<int> va(a, a + 4);
    Solution s;
    s.minNumber(va);
    return 0;
}
