package com.aacirq.string;

import java.util.LinkedList;

public class N54 {
    public static void main(String[] args) {
        N54 sol = new N54();

        // gggll
        sol.Insert('g');
        System.out.print(sol.FirstAppearingOnce());
        sol.Insert('o');
        System.out.print(sol.FirstAppearingOnce());
        sol.Insert('o');
        System.out.print(sol.FirstAppearingOnce());
        sol.Insert('g');
        sol.Insert('l');
        System.out.print(sol.FirstAppearingOnce());
        sol.Insert('e');
        System.out.print(sol.FirstAppearingOnce());
    }

    int[] m = new int[256];
    LinkedList<Character> list = new LinkedList<>();
    //Insert one char from stringstream
    public void Insert(char ch) {
        m[ch]++;
        if (m[ch] == 1) {
            list.add(ch);
        }
    }
    //return the first appearence once char in current stringstream
    public char FirstAppearingOnce() {
        while (list.size() != 0 && m[list.get(0)] > 1) {
            list.remove(0);
        }
        if (list.size() == 0) {
            return '#';
        } else {
            return list.get(0);
        }
    }
}
