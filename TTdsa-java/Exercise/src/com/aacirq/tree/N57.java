package com.aacirq.tree;

public class N57 {
    public static void main(String[] args) {
        N57 sol = new N57();

    }

    public TreeLinkNode GetNext(TreeLinkNode pNode) {
        TreeLinkNode node;
        if (pNode.right != null) {
            node = pNode.right;
            while (node.left != null) {
                node = node.left;
            }
        } else {
            node = pNode.next;
            while (node != null && node.right == pNode) {
                pNode = node;
                node = node.next;
            }
        }
        return node;
    }
}
