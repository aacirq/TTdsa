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
        HashMap<Integer, Boolean> hash = new HashMap<>();
        for (int i : array) {
            hash.put(i, !hash.containsKey(i));
        }

        int[] res = new int[2];
        int ind = 0;

        for (Map.Entry<Integer, Boolean> entry : hash.entrySet()) {
            if (entry.getValue()) {
                res[ind] = entry.getKey();
                ind++;
            }
        }

        if (res[0] > res[1]) {
            int tmp = res[0];
            res[0] = res[1];
            res[1] = tmp;
        }
        return res;
    }
}
