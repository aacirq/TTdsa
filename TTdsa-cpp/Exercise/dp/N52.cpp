//
// Created by renxin on 2021/6/12.
//

#include "ttdsa.h"

class Solution {
public:
    bool match(string str, string pattern) {
        int m = str.size() + 1;
        int n = pattern.size() + 1;

        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for (int j = 2; j < n; j++)
            dp[0][j] = pattern[j - 1] == '*' && dp[0][j - 2];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (pattern[j - 1] == '*') {
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (pattern[j-2]==str[i-1] || pattern[j-2]=='.'));
                } else {
                    dp[i][j] = dp[i-1][j-1] && (pattern[j-1]==str[i-1] || pattern[j-1]=='.');
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;

    // 1
    cout << sol.match("aaa", "a*a") << endl;
    // 1
    cout << sol.match("a", ".*") << endl;

    return 0;
}