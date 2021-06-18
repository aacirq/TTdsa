package com.aacirq.math;

public class N11 {
    public static void main(String[] args) {
        N11 sol = new N11();

        // 2
        System.out.println(sol.NumberOf1(10));
    }

    public int NumberOf1(int n) {
        int res = 0;
        while (n != 0) {
            res++;
            n &= (n - 1);
        }
        return res;
    }
}
