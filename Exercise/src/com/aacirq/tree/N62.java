package com.aacirq.tree;

import java.util.LinkedList;
import java.util.Stack;

public class N62 {
    public static void main(String[] args) {
        N62 sol = new N62();

        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(4);
        root.right = new TreeNode(7);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(8);

        System.out.println(sol.KthNode(root, 3).val);
    }

    TreeNode KthNode(TreeNode pRoot, int k) {
        if (pRoot != null) {
            int n = 0;
            Stack<TreeNode> s = new Stack<>();
            while (pRoot != null || s.size() != 0) {
                if (pRoot == null) {
                    pRoot = s.pop();
                    n++;
                    if (n == k) return pRoot;
                    pRoot = pRoot.right;
                } else {
                    s.push(pRoot);
                    pRoot = pRoot.left;
                }
            }
        }
        return null;
    }
}
