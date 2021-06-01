package com.aacirq.tree;

import java.util.Arrays;

public class N23 {
    public static void main(String[] args) {
        N23 sol = new N23();

        int[] sequence = {4, 8, 6, 12, 16, 14, 10};
        // true
        System.out.println(sol.VerifySquenceOfBST(sequence));

        int[] sequence2 = {4, 8, 6, 12, 16, 13, 14, 2};
        // false
        System.out.println(sol.VerifySquenceOfBST(sequence2));
    }

    public int[] sequence;

    public boolean VerifySquenceOfBST(int[] sequence) {
        if (sequence.length == 0)
            return false;
        this.sequence = Arrays.copyOf(sequence, sequence.length);
        return fun(0, sequence.length - 1);
    }

    public boolean fun(int left, int right) {
        if (left >= right)
            return true;
        int headValue = sequence[right];
        int mid = left;
        while (sequence[mid] < headValue) {
            mid++;
        }
        for (int i = mid; i < right; i++) {
            if (sequence[i] <= headValue)
                return false;
        }
        return fun(left, mid - 1) && fun(mid, right - 1);
    }
}
