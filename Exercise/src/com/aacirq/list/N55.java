package com.aacirq.list;

import java.util.HashSet;
import java.util.Set;

public class N55 {
    public static void main(String[] args) {
        N55 sol = new N55();

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = head.next;

        // 2
        System.out.println(sol.EntryNodeOfLoop(head).val);
    }

    public ListNode EntryNodeOfLoop(ListNode pHead) {
        Set<ListNode> set = new HashSet<>();
        ListNode node = pHead;
        while (node != null && !set.contains(node)) {
            set.add(node);
            node = node.next;
        }
        return node;
    }

    /**
     * 奇技淫巧方法
     * @param pHead head of a List
     * @return entry node of loop if this list have loop, or null otherwise.
     */
    public ListNode EntryNodeOfLoop2(ListNode pHead) {
        ListNode fast = pHead, slow = pHead;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
                break;
        }

        if (fast == null || fast.next == null)
            return null;

        fast = pHead;

        while (fast != slow) {
            fast = fast.next;
            slow = slow.next;
        }
        return fast;
    }
}
