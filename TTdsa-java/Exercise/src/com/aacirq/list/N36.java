package com.aacirq.list;

public class N36 {
    public static void main(String[] args) {
        N36 sol = new N36();

        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = new ListNode(4);

        ListNode head2 = new ListNode(5);
        head2.next = head1.next.next;

        System.out.println(sol.FindFirstCommonNode(head1, head2).val);
    }

    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
        if (pHead1 == null || pHead2 == null)
            return null;

        ListNode node1 = pHead1;
        ListNode node2 = pHead2;
        while (node1 != node2) {
            node1 = (node1 == null) ? pHead2 : node1.next;
            node2 = (node2 == null) ? pHead1 : node2.next;
        }

        return node1;
    }
}
