// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 **/

// @lc code=start
class Solution
{
private:
    stack<char> st;
    unordered_map<char,char> pairs={
        {')','('},
        {']','['},
        {'}','{'}
    };
public:
    bool isValid(string s)
    {
        for (auto &&ch : s)
        {
            if(pairs.count(ch)){//如果ch不是key,那么就是左括号
                if(st.empty()||st.top()!=pairs[ch])//如果栈空还遇到右括号 或者 左右括号不匹配 
                    return false;
                st.pop();//匹配括号弹栈
            }else//左括号压栈
                st.push(ch);
        }
        return st.empty();//如果栈空,说明都匹配掉了
    }
};
// @lc code=end
