package com.aacirq.list;

public class ListNode {
    public int val;
    public ListNode next = null;

    public ListNode(int val) {
        this.val = val;
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.printf("%d ->", head.val);
            head = head.next;
        }
        System.out.println("");
    }
}
