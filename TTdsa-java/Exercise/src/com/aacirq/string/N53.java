package com.aacirq.string;

public class N53 {
    public static void main(String[] args) {
        N53 sol = new N53();

        // 全true
        System.out.println(
                sol.isNumeric("+100") + " "
                        + sol.isNumeric("5e2") + " "
                        + sol.isNumeric("-123") + " "
                        + sol.isNumeric("3.1416") + " "
                        + sol.isNumeric("123.45e+6") + " "
                        + sol.isNumeric("-.123") + " "
                        + sol.isNumeric(".123") + " "
                        + sol.isNumeric("-1E-16")
        );
        // 全false
        System.out.println(
                sol.isNumeric("12e") + " "
                        + sol.isNumeric("1a3.14") + " "
                        + sol.isNumeric("+e3") + " "
                        + sol.isNumeric("1.2.3") + " "
                        + sol.isNumeric("+-5") + " "
                        + sol.isNumeric("12e4.3")
        );
    }

    public boolean isNumeric(String str) {
        if (str.length() == 0) return false;
        int ind = 0;
        if (str.charAt(ind) == '+' || str.charAt(ind) == '-') {
            ind++;
            if (ind == str.length() || ((str.charAt(ind)<'0' || str.charAt(ind)>'9') && str.charAt(ind) != '.')) return false;
        }
        while (ind < str.length() && str.charAt(ind) >= '0' && str.charAt(ind) <= '9') ind++;
        if (ind == str.length()) return true;

        if (str.charAt(ind) == '.') {
            ind++;
            if (ind == str.length() || str.charAt(ind) < '0' || str.charAt(ind) > '9') return false;
            while (ind < str.length() && str.charAt(ind) >= '0' && str.charAt(ind) <= '9') ind++;
            if (ind == str.length()) return true;
        }

        if (str.charAt(ind) == 'e' || str.charAt(ind) == 'E') {
            ind++;
            if (ind < str.length() && (str.charAt(ind) == '+' || str.charAt(ind) == '-'))
                ind++;
        } else {
            return false;
        }

        if (ind == str.length()) return false;
        while (ind < str.length() && str.charAt(ind) >= '0' && str.charAt(ind) <= '9') ind++;
        return ind == str.length();
    }
}
