#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream> // for istringstream
#include <iterator> //for istream_iterator
#include <algorithm>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        istringstream iss(s);
        vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());

        if (results.size() == 0)
            return "";

        reverse(results.begin(), results.end());

        ostringstream vts;
        copy(results.begin(), results.end() - 1, ostream_iterator<string>(vts, " "));
        vts << results.back();

        return vts.str();
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    s.reverseWords("");
    return 0;
}
