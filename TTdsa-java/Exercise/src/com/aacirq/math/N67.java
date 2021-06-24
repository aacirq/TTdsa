package com.aacirq.math;

public class N67 {
    public static void main(String[] args) {
        N67 sol = new N67();

        // 1
        System.out.println(sol.cutRope(2));
        // 4
        System.out.println(sol.cutRope(4));
        // 36
        System.out.println(sol.cutRope(10));
    }

    public int cutRope(int target) {
        if (target <= 3)
            return target - 1;
        int a = target / 3, b = target % 3;
        double res;
        if (b == 0) {
            res = Math.pow(3, a);
        } else if (b == 1) {
            res = Math.pow(3, a-1) * 4;
        } else {
            res = Math.pow(3, a) * 2;
        }
        return (int)res;
    }
}
