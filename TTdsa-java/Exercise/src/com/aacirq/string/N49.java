package com.aacirq.string;

public class N49 {
    public static void main(String[] args) {
        N49 sol = new N49();

        System.out.println(sol.StrToInt("+2147483647"));
    }

    public int StrToInt(String str) {
        if (str.length() == 0)
            return 0;
        int sign = 1;
        int res = 0;
        int ind = 0;
        if (str.charAt(ind) == '-') {
            sign = -1;
            ind++;
        } else if (str.charAt(ind) == '+') {
            sign = 1;
            ind++;
        }
        while (ind < str.length()) {
            if (str.charAt(ind) < '0' || str.charAt(ind) > '9')
                return 0;
            res = 10 * res + str.charAt(ind) - '0';
            ind++;
        }
        return res * sign;
    }
}
