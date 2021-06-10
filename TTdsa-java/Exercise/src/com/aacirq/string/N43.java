package com.aacirq.string;

public class N43 {
    public static void main(String[] args) {
        N43 sol = new N43();

        // "XYZdefabc"
        System.out.println(sol.LeftRotateString("abcXYZdef", 3));
        // "a"
        System.out.println(sol.LeftRotateString("a", 3));
    }

    public String LeftRotateString(String str,int n) {
        if (str.length() == 0)
            return str;
        n %= str.length();
        return str.substring(n) + str.substring(0, n);
    }
}
