#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vflag(m,vector<bool> (n,false));
        return DFS(0,0,m,n,k,vflag);
    }
    int DFS(int r,int c,int m,int n,int k,vector<vector<bool>>& vflag){
        int sum=1;
        int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        vflag[r][c]=true;
        for(auto dir:direction){
            int temp_r=r+dir[0],temp_c=c+dir[1];
            if(temp_r<m&&temp_r>=0&&temp_c<n&&temp_c>=0&&!vflag[temp_r][temp_c]&&can_go(temp_r,temp_c,k)){
                sum+=DFS(temp_r,temp_c,m,n,k,vflag);
            }
        }
        return sum;
    }
    bool can_go(int r,int c,int k){
        int sum=0;
        while(r!=0||c!=0){
            sum+=(r%10+c%10);
            r/=10;
            c/=10;
        }
        return k>=sum;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.movingCount(7,2,3);
    return 0;
}
