#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

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

int main(int argc, char const *argv[]) {
  MedianFinder m;
  int a[]={6,10,2,6,5,0,6,3,1,0,0};
  for (int ac: a){
    m.addNum(ac);
    m.findMedian();
  }
  return 0;
}
