package com.aacirq.array;

public class N51 {
    public static void main(String[] args) {
        N51 sol = new N51();

        int[] nums = {1, 2, 3, 4, 5};
        // [120 60 40 30 24 ]
        printArray(sol.multiply(nums));
    }

    public static void printArray(int[] array) {
        System.out.printf("[");
        for (int ele : array) {
            System.out.printf(ele + " ");
        }
        System.out.println("]");
    }

    public int[] multiply(int[] A) {
        int[] res = new int[A.length];
        int pre = 1;
        for (int i = 0; i < A.length; i++) {
            res[i] = pre;
            pre *= A[i];
        }
        int post = 1;
        for (int i = A.length - 1; i >= 0; i--) {
            res[i] *= post;
            post *= A[i];
        }
        return res;
    }
}
