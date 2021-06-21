//
// Created by renxin on 2021/6/21.
//

#include "ttdsa.h"

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n == 0 || m == 0)
            return -1;
        int f = 0;
        for (int i = 2; i <= n; i++) {
            f = (f + m) % i;
        }
        return f;
    }
};

int main() {
    Solution sol;
    // 3
    cout << sol.LastRemaining_Solution(5, 3) << endl;
    return 0;
}