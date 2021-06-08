package com.aacirq.list;

import java.util.ArrayList;
import java.util.LinkedList;

public class N03 {
    public static void main(String[] args) {
        N03 sol = new N03();

        ListNode head = new ListNode(67);
        head.next = new ListNode(0);
        head.next.next = new ListNode(24);
        head.next.next.next = new ListNode(58);
        System.out.println(sol.printListFromTailToHead(head));
    }

    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        LinkedList<Integer> list = new LinkedList<>();
        while (listNode != null) {
            list.addFirst(listNode.val);
            listNode = listNode.next;
        }
        return new ArrayList<>(list);
    }
}
