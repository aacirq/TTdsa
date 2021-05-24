package com.aacirq.list;

public class N16 {
    public static void main(String[] args) {
        N16 sol = new N16();

        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(3);
        head1.next.next = new ListNode(5);

        ListNode head2 = new ListNode(2);
        head2.next = new ListNode(4);
        head2.next.next = new ListNode(6);

        ListNode.printList(sol.Merge(head1, head2));
    }

    public ListNode Merge(ListNode list1, ListNode list2) {
        ListNode retHead = new ListNode(0);
        ListNode cur = retHead;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                cur.next = list1;
                list1 = list1.next;
            } else {
                cur.next = list2;
                list2 = list2.next;
            }
            cur = cur.next;
        }
        if (list1 != null) {
            cur.next = list1;
        }
        if (list2 != null) {
            cur.next = list2;
        }
        return retHead.next;
    }
}
