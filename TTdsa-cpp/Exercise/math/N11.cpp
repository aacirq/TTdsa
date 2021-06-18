//
// Created by renxin on 2021/6/18.
//

#include "ttdsa.h"

class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        while (n != 0) {
            res++;
            n = n & (n - 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    // 2
    cout << sol.NumberOf1(10) << endl;
    return 0;
}