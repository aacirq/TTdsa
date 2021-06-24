package com.aacirq.math;

public class N48 {
    public static void main(String[] args) {
        N48 sol = new N48();

        // 3
        System.out.println(sol.Add(1, 2));
        // 1
        System.out.println(sol.Add(-1, 2));
    }

    public int Add(int n1,int n2) {
        while (n2 != 0) {
            int c = (n1 & n2) << 1;
            n1 ^= n2;
            n2 = c;
        }
        return n1;
    }
}
