package com.aacirq.list;

public class N25 {
    public static void main(String[] args) {
        N25 sol = new N25();

        RandomListNode head = new RandomListNode(1);
        head.next = new RandomListNode(2);
        head.next.next = new RandomListNode(3);
        head.next.next.next = new RandomListNode(4);
        head.next.next.next.next = new RandomListNode(5);

        head.random = head.next.next;
        head.next.next.random = head.next.next.next.next;

        RandomListNode.print(head);
        RandomListNode.print(sol.Clone(head));

        RandomListNode.print(null);
        RandomListNode.print(sol.Clone(null));
    }

    public RandomListNode Clone(RandomListNode pHead) {
        if (pHead == null)
            return null;
        RandomListNode cur = pHead;
        while (cur != null) {
            RandomListNode tmp = cur.next;
            cur.next = new RandomListNode(cur.label);
            cur.next.next = tmp;
            cur = tmp;
        }

        cur = pHead;
        while (cur != null) {
            if (cur.random != null)
                cur.next.random = cur.random.next;
            cur = cur.next.next;
        }

        cur = pHead;
        RandomListNode resHead = new RandomListNode(0);
        RandomListNode curRes = resHead;
        while (cur != null) {
            curRes.next = cur.next;
            curRes = curRes.next;
            cur.next = curRes.next;
            cur = cur.next;
        }

        return resHead.next;
    }
}
