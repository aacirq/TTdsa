package com.aacirq.math;

public class N67 {
    public static void main(String[] args) {
        N67 sol = new N67();

        // 1
        System.out.println(sol.cutRope(1));
        // 4
        System.out.println(sol.cutRope(4));
        // 36
        System.out.println(sol.cutRope(10));
    }

    public int cutRope(int target) {
        int[] dp = new int[target + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int n = 2; n <= target; n++) {
            for (int i = n/2; i > 0; i--) {
                int t1 = Math.max(i, dp[i]);
                int t2 = Math.max(n-i, dp[n-i]);
                dp[n] = Math.max(t1 * t2, dp[n]);
            }
        }
        return dp[target];
    }
}
