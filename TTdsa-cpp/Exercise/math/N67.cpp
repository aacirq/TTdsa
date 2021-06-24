//
// Created by renxin on 2021/6/24.
//

#include "ttdsa.h"
#include <cmath>

class Solution {
public:
    int cutRope(int number) {
        if (number <= 3) return number - 1;
        int a = number / 3, b = number % 3;
        int res;
        if (b == 0) {
            res = std::pow(3, a);
        } else if (b == 1) {
            res = std::pow(3, a - 1) * 4;
        } else {
            res = std::pow(3, a) * 2;
        }
        return res;
    }
};

int main() {
    Solution sol;
    // 1
    cout << sol.cutRope(2) << endl;
    // 4
    cout << sol.cutRope(4) << endl;
    // 36
    cout << sol.cutRope(10) << endl;
    return 0;
}