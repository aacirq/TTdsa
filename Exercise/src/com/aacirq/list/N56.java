package com.aacirq.list;

public class N56 {
    public static void main(String[] args) {
        N56 sol = new N56();

        ListNode pHead = new ListNode(1);
        pHead.next = new ListNode(2);
        pHead.next.next = new ListNode(3);
        pHead.next.next.next = new ListNode(3);
        pHead.next.next.next.next = new ListNode(4);
        pHead.next.next.next.next.next = new ListNode(4);
        pHead.next.next.next.next.next.next = new ListNode(5);

        // 1 ->2 ->3 ->3 ->4 ->4 ->5 ->
        ListNode.printList(pHead);
        // 1 ->2 ->5 ->
        ListNode.printList(sol.deleteDuplication(pHead));

        // 1 ->
        ListNode.printList(sol.deleteDuplication(new ListNode(1)));
    }

    public ListNode deleteDuplication(ListNode pHead) {
        ListNode addedHead = new ListNode(0);
        addedHead.next = pHead;

        ListNode pre = addedHead;
        ListNode cur = pHead;
        while (cur != null) {
            if (cur.next != null && cur.next.val == cur.val) {
                int curVal = cur.val;
                while (cur != null && cur.val == curVal) {
                    cur = cur.next;
                }
                pre.next = cur;
            } else {
                pre = pre.next;
                cur = cur.next;
            }
        }
        return addedHead.next;
    }
}
