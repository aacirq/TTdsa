package com.aacirq.stack;

import java.util.Stack;

public class N05 {
    public static void main(String[] args) {
        N05 sol = new N05();

        sol.push(1);
        sol.push(2);
        sol.push(3);
        // 1
        System.out.println(sol.pop());
        sol.push(4);
        // 2
        System.out.println(sol.pop());
        sol.push(5);
        // 3
        System.out.println(sol.pop());
        // 4
        System.out.println(sol.pop());
        // 5
        System.out.println(sol.pop());
    }

    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();

    public void push(int node) {
        stack1.push(node);
    }

    public int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }
}
