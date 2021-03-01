#include <iostream>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
private:
    stack<int> stIn;
    stack<int> stOut;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int result=this->peek();//获得队头
        stOut.pop();//弹出队头
        return result;
    }

    /** Get the front element. */
    int peek()
    {
        if (stOut.empty())//如果Out栈为空
        {
            while (!stIn.empty())//把In栈里的所有元素拿过来用来输出
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result=stOut.top();
        return result;//返回栈顶元素
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stIn.empty()&&stOut.empty();//如果两个栈都是空的那么就是空的
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end