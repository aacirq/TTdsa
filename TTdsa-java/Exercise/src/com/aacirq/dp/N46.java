package com.aacirq.dp;

public class N46 {
    public static void main(String[] args) {
        N46 sol = new N46();

        System.out.println(sol.LastRemaining_Solution(5, 3));
    }

    public int LastRemaining_Solution(int n, int m) {
        if (n == 0)
            return -1;
        int dp = 0;
        for (int i = 2; i <= n; i++) {
            dp = (dp + m) % i;
        }
        return dp;
    }
}
