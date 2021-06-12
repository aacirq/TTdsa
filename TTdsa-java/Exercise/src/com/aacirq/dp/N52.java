package com.aacirq.dp;

public class N52 {
    public static void main(String[] args) {
        N52 sol = new N52();

        // true
        System.out.println(sol.match("aaa", "a*a"));
        // true
        System.out.println(sol.match("a", ".*"));
    }

    public boolean match(String str, String pattern) {
        int m = str.length() + 1;
        int n = pattern.length() + 1;
        boolean[][] dp = new boolean[m][n];
        dp[0][0] = true;
        for (int j = 2; j < n; j+=2) {
            dp[0][j] = pattern.charAt(j-1) == '*' && dp[0][j-2];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (pattern.charAt(j-1) == '*') {
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (pattern.charAt(j-2)==str.charAt(i-1) || pattern.charAt(j-2)=='.'));
                } else {
                    dp[i][j] = dp[i-1][j-1] && (pattern.charAt(j-1) == str.charAt(i-1) || pattern.charAt(j-1) == '.');
                }
            }
        }
        return dp[m-1][n-1];
    }
}
