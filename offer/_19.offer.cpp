#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int begin=0;
        int end=s.length()-1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i]!=' '){
                end=i; break;
            }
        }
        for (size_t i = 0; i < s.length(); i++)
        {
            if(s[i]!=' '){
                begin=i; break;
            }
        }
        int count_cdot=0;
        for(int i=begin;i<end;i++){
            if(s[i]==' ')
                return false;
            if(s[i]=='.')
             count_cdot++;
        }
        if(count_cdot>1)
            return false;
        if(s[0]=='.'){
            if(s.length()==1)
                return false;
            if(s[1]<58&&s[1]>47)
            s='0'+s;
        }
        if(s[s.length()-1]=='e')
            return false;
        try
        {
            int a=stoi(s);
            cout<<a;
        }
        catch(const std::exception& e)
        {
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.isNumber("0..");
    return 0;
}
