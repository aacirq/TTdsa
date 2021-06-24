//
// Created by renxin on 2021/6/24.
//

#include "ttdsa.h"

class Solution {
public:
    int cutRope(int number) {
        vector<int> dp(number + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int n = 2; n <= number; n++) {
            for (int i = n/2; i > 0; i--) {
                int t1 = std::max(i, dp[i]);
                int t2 = std::max(n-i, dp[n-i]);
                dp[n] = std::max(dp[n], t1 * t2);
            }
        }
        return dp[number];
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