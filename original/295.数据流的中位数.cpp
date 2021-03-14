// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem295.h"

using namespace std;
// @before-stub-for-debug-end

#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
using namespace std;
/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start

class MedianFinder {
private:
  multiset<double> data;
  multiset<double>::iterator mid;

public:
  /** initialize your data structure here. */
  MedianFinder() { mid = data.end(); }

  void addNum(int num) {
    data.insert(num);
    int length = data.size();
    if(length==1)
      mid=data.begin();
    if(length%2==0&&num < *mid)
      mid=prev(mid);
    else if(length%2==1&&num > *mid){
      mid=next(mid);
    }
  }

  double findMedian() {
    if(data.size()%2==0){
      cout<<(*mid+*(next(mid)))/2<<"  /2"<<endl;
      return (*mid+*(next(mid)))/2;
    }else{
      cout<< *mid<<endl;
      return *mid;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

