package com.aacirq.stack;

import java.util.Queue;
import java.util.Stack;

public class N20 {
    public static void main(String[] args) {
        N20 sol = new N20();

        sol.push(-1);
        sol.push(2);
        // -1
        System.out.println(sol.min());
        // 2
        System.out.println(sol.top());
        sol.pop();
        sol.push(1);
        // 1
        System.out.println(sol.top());
        // -1
        System.out.println(sol.min());
    }

    private Stack<Integer> valStack = new Stack<>();
    private Stack<Integer> minStack = new Stack<>();

    public void push(int node) {
        valStack.push(node);
        if (minStack.empty()) {
            minStack.push(node);
        } else {
            if (node < minStack.peek()) {
                minStack.push(node);
            } else {
                minStack.push(minStack.peek());
            }
        }
    }

    public void pop() {
        valStack.pop();
        minStack.pop();
    }

    public int top() {
        return valStack.peek();
    }

    public int min() {
        return minStack.peek();
    }
}
