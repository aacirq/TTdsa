package com.aacirq.tree;

import java.util.LinkedList;
import java.util.Queue;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }

    /**
     * 层序遍历输出
     * @param root 根节点
     */
    public static void print(TreeNode root) {
        System.out.print("[");
        if (root != null) {
            Queue<TreeNode> q = new LinkedList<>();
            q.add(root);
            TreeNode curNode = q.poll();
            while (curNode != null) {
                System.out.printf("%d ", curNode.val);
                if (curNode.left != null)
                    q.add(curNode.left);
                if (curNode.right != null)
                    q.add(curNode.right);
                curNode = q.poll();
            }
        }
        System.out.println("]");
    }
}