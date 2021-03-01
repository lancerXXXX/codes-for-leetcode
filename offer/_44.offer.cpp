#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        int total_digit_num = 0, result = 0;
        while (true) {
            long temp = n - (total_digit_num + 1) * 9 * pow(10, total_digit_num);
            if (temp > 0) n = temp;
            else break;
            total_digit_num++;
        }
        n--;
        int quotient = n / (total_digit_num + 1);
        quotient += pow(10, total_digit_num);
        int remainder = n % (total_digit_num + 1);
        int step = total_digit_num + 1 - remainder;
        while (step > 0) {
            result = quotient % 10;
            quotient /= 10;
            step--;
        }
        return result;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    for (int i = 0;i < 200;i++) {
        cout << "i :" << i << "  " << s.findNthDigit(i) << endl;
    }
    return 0;
}
