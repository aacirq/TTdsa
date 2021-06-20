//
// Created by renxin on 2021/6/20.
//

#include "ttdsa.h"

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        long b = 1;
        int tn = n;
        int res = 0;
        while (tn != 0) {
            res += tn / 10 * b;
            if (tn % 10 > 1) {
                res += b;
            } else if (tn % 10 == 1) {
                res += n % b + 1;
            }
            tn /= 10;
            b *= 10;
        }
        return res;
    }
};

int main() {
    Solution sol;

    for (int i = 0; i < 30; i++) {
        cout << "n = " << i << ": " << sol.NumberOf1Between1AndN_Solution(i)
             << "| n = " << 100 + i << ": " << sol.NumberOf1Between1AndN_Solution(100 + i)
             << "| n = " << 200 + i << ": " << sol.NumberOf1Between1AndN_Solution(200 + i)
             << endl;
    }
    return 0;
}