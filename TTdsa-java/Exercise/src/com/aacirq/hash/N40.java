package com.aacirq.hash;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class N40 {
    public static void main(String[] args) {
        N40 sol = new N40();

        int[] array = {1, 4, 1, 6};
        System.out.println(Arrays.toString(sol.FindNumsAppearOnce(array)));
    }

    public int[] FindNumsAppearOnce(int[] array) {
        int x = 0;
        for (int i : array) {
            x ^= i;
        }
        int m = 1;
        while ((x & m) == 0) {
            m <<= 1;
        }
        int[] res = {0, 0};
        for (int i : array) {
            if ((m & i) == 0) res[0] ^= i;
            else res[1] ^= i;
        }

        if (res[0] > res[1]) {
            int tmp = res[0];
            res[0] = res[1];
            res[1] = tmp;
        }
        return res;
    }
}
