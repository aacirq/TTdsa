package com.aacirq.dp;

public class N07 {
    public static void main(String[] args) {
        N07 sol = new N07();

        for (int i = 0; i < 10; i++) {
            System.out.println(sol.Fibonacci(i));
        }
    }

    public int Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int v1 = 0;
        int v2 = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = v2;
            v2 += v1;
            v1 = tmp;
        }
        return v2;
    }
}
