package com.aacirq.math;

public class N31 {
    public static void main(String[] args) {
        N31 sol = new N31();
        // 6
        System.out.println(sol.NumberOf1Between1AndN_Solution(13));
    }

    public int NumberOf1Between1AndN_Solution(int n) {
        long b = 1;
        int tn = n;
        int res = 0;
        while (tn != 0) {
            res += tn / 10 * b;
            if (tn % 10 > 1) {
                res += b;
            } else if (tn % 10 == 1) {
                res += n % b + 1;
            }
            tn /= 10;
            b *= 10;
        }
        return res;
    }
}
