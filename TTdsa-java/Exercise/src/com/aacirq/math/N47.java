package com.aacirq.math;

public class N47 {
    public static void main(String[] args) {
        N47 sol = new N47();

        System.out.println(sol.Sum_Solution(5));
    }

    private int res = 0;
    public int Sum_Solution(int n) {
        boolean b = (n > 0) && (Sum_Solution(n - 1) > 0);
        res += n;
        return res;
    }
}
