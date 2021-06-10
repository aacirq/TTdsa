package com.aacirq.hash;

import java.util.HashMap;

public class N34 {
    public static void main(String[] args) {
        N34 sol = new N34();

        // 4
        System.out.println(sol.FirstNotRepeatingChar("google"));
        // -1
        System.out.println(sol.FirstNotRepeatingChar(""));
    }

    public int FirstNotRepeatingChar(String str) {
        HashMap<Character, Boolean> m = new HashMap<>();
        char[] cArray = str.toCharArray();
        for (char c : cArray) {
            m.put(c, !m.containsKey(c));
        }
        for (int i = 0; i < str.length(); i++) {
            if (m.get(cArray[i]))
                return i;
        }
        return -1;
    }
}
