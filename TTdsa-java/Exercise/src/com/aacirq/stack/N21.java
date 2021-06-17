package com.aacirq.stack;

import java.util.Stack;

public class N21 {
    public static void main(String[] args) {
        N21 sol = new N21();

        int[] pushA = {1, 2, 3, 4, 5};
        int[] popA1 = {4, 3, 5, 1, 2};
        int[] popA2 = {4, 5, 3, 2, 1};

        // false
        System.out.println(sol.IsPopOrder(pushA, popA1));
        // true
        System.out.println(sol.IsPopOrder(pushA, popA2));
    }

    public boolean IsPopOrder(int[] pushA, int[] popA) {
        Stack<Integer> s = new Stack<>();
        int indPop = 0;
        for (int i : pushA) {
            s.push(i);
            while (!s.empty() && s.peek() == popA[indPop]) {
                s.pop();
                indPop++;
            }
        }
        return s.empty();
    }
}
