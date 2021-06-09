package com.aacirq.string;

public class N02 {
    public static void main(String[] args) {
        N02 sol = new N02();
        // "We%20Are%20Happy"
        System.out.println(sol.replaceSpace("We Are Happy"));
    }

    public String replaceSpace(String s) {
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                str.append("%20");
            } else {
                str.append(s.charAt(i));
            }
        }
        return str.toString();
    }
}
