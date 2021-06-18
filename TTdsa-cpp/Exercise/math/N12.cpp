//
// Created by renxin on 2021/6/18.
//

#include "ttdsa.h"

class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0)
            return 0;
        double b = base;
        long e = exponent;
        if (e < 0) {
            b = 1/b;
            e = -e;
        }
        double res = 1.0;
        while (e != 0) {
            if ((e & 1) != 0)
                res *= b;
            b *= b;
            e >>= 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    // 8.00000
    cout << sol.Power(2.0, 3) << endl;
    // 9.26100
    cout << sol.Power(2.1, 3) << endl;
    // 0.25000
    cout << sol.Power(2.0, -2) << endl;
    return 0;
}