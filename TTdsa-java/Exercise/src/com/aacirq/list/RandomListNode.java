package com.aacirq.list;

public class RandomListNode {
    public int label;
    public RandomListNode next = null;
    public RandomListNode random = null;

    public RandomListNode(int label) {
        this.label = label;
    }

    public static void print(RandomListNode node) {
        while (node != null) {
            System.out.print(node.label);
            if (node.random == null) {
                System.out.print("(null)");
            } else {
                System.out.printf("(%d)", node.random.label);
            }
            System.out.print(" -> ");
            node = node.next;
        }
        System.out.println("");
    }
}
