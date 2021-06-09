package com.aacirq.string;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class N27 {
    public static void main(String[] args) {
        N27 sol = new N27();

        // Vector (2): [ ab, ba ]
        System.out.println(sol.Permutation("ab"));

        // Vector (1): [ aaa ]
        System.out.println(sol.Permutation("aaa"));

        // Vector (1): [ aaa ]
        System.out.println(sol.Permutation("baaa"));

        // Vector (14): [ aabd, aadb, abad, abda, adab, adba, baad, bada, bdaa, daab, daab, daba, daba, dbaa ]
        System.out.println(sol.Permutation("abad"));
    }

    public ArrayList<String> Permutation(String str) {
        res = new ArrayList<>();
        perm(str.toCharArray(), 0);
        Collections.sort(res);
        return res;
    }

    private ArrayList<String> res;
    private void perm(char[] cArray, int ind) {
        if (ind == cArray.length - 1) {
            res.add(String.valueOf(cArray));
            return;
        }
        HashSet<Character> s = new HashSet<>();
        for (int i = ind; i < cArray.length; i++) {
            if (s.contains(cArray[i]))
                continue;
            s.add(cArray[i]);
            swap(cArray, ind, i);
            perm(cArray, ind + 1);
            swap(cArray, ind, i);
        }
    }

    private void swap(char[] cArray, int ind1, int ind2) {
        char c = cArray[ind1];
        cArray[ind1] = cArray[ind2];
        cArray[ind2] = c;
    }
}
