package com.aacirq.list;

public class N14 {
    public static void main(String[] args) {
        N14 sol = new N14();

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        ListNode res_node = null;
        res_node = sol.FindKthToTail(head, 1);
        // {5}
        System.out.println("{" + res_node.val + "}");

        res_node = sol.FindKthToTail(head, 2);
        // {4}
        System.out.println("{" + res_node.val + "}");

        // 另一个链表
        ListNode head2 = new ListNode(1);
        res_node = sol.FindKthToTail(head2, 1);
        // {1}
        System.out.println("{" + res_node.val + "}");

        res_node = sol.FindKthToTail(null, 100);
        // {null}
        System.out.println("{" + res_node + "}");
    }

    public ListNode FindKthToTail(ListNode pHead, int k) {
        ListNode fast = pHead;
        ListNode slow = pHead;
        while (k-- != 0) {
            if (fast == null) {
                return null;
            }
            fast = fast.next;
        }
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
}
