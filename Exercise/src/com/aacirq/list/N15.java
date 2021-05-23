package com.aacirq.list;

public class N15 {
    public static void main(String[] args) {
        N15 sol = new N15();

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        printList(sol.ReverseList(head));

        // 另一个链表
        ListNode head2 = new ListNode(1);
        printList(sol.ReverseList(head2));
    }

    public ListNode ReverseList(ListNode head) {
        if (head == null)
            return null;

        ListNode cur = head;
        ListNode post = head.next;
        cur.next = null;

        while (post != null) {
            ListNode tmp = post.next;
            post.next = cur;
            cur = post;
            post = tmp;
        }

        return cur;
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.printf("%d ->", head.val);
            head = head.next;
        }
        System.out.println("");
    }
}
