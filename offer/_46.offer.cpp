#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        if(num<=9) return 1;
        int two = num % 100;
        if(two>9&&two<26){ // 如果是 xxx06这种 -> %10: 6 ; %100: 6 所以要得是两位数才有意义
            return translateNum(num / 10)+translateNum(num/100);
        }else{
            return translateNum(num/10);
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    s.translateNum(506);
    return 0;
}
