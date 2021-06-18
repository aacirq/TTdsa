package com.aacirq.math;

public class N12 {
    public static void main(String[] args) {
        N12 sol = new N12();

        // 8.00000
        System.out.println(sol.Power(2.0, 3));
        // 9.26100
        System.out.println(sol.Power(2.1, 3));
        // 0.25000
        System.out.println(sol.Power(2.0, -2));
    }

    public double Power(double base, int exponent) {
        if (base == 0)
            return 0;
        long e = exponent;
        double b = base;
        if (e < 0) {
            b = 1/b;
            e = -e;
        }
        double res = 1.0;
        while (e != 0) {
            if ((e & 1) != 0)
                res *= b;
            b *= b;
            e >>= 1;
        }
        return res;
    }
}
