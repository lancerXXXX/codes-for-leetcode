#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class CQueue
{
private:
    stack<int> sin;
    stack<int> sout;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        sin.push(value);
    }

    int deleteHead()
    {
        if (sout.empty())
        {
            while (!sin.empty())
            {
                sout.push(sin.top());
                sin.pop();
            }
        }
        if (!sout.empty())
        {
            int temp = sout.top();
            sout.pop();
            return temp;
        }
        else
        {
            return -1;
        }
    }
};
