//
// Created by renxin on 2021/6/18.
//

#include "ttdsa.h"

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent < 0) {
            return 1.0 / fun(base, -exponent);
        } else {
            return fun(base, exponent);
        }
    }

private:
    double fun(double base, int exponent) {
        if (exponent == 0)
            return 1.0;
        if (exponent == 1)
            return base;
        double part = fun(base, exponent / 2);
        if (exponent % 2 == 0)
            return part * part;
        else
            return part * part * base;
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