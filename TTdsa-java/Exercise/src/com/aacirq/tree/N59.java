package com.aacirq.tree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Stack;

public class N59 {
    public static void main(String[] args) {
        N59 sol = new N59();

        TreeNode pRoot = new TreeNode(8);
        pRoot.left = new TreeNode(6);
        pRoot.left.left = new TreeNode(5);
        pRoot.left.right = new TreeNode(7);
        pRoot.right = new TreeNode(10);
        pRoot.right.left = new TreeNode(9);
        pRoot.right.right = new TreeNode(11);

        // [[8], [10, 6], [5, 7, 9, 11]]
        System.out.println(sol.Print(pRoot));
    }

    public ArrayList<ArrayList<Integer>> Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        if (pRoot != null) {
            Stack<TreeNode> s1 = new Stack<>();
            Stack<TreeNode> s2 = new Stack<>();
            s1.push(pRoot);
            while (!s1.empty() || !s2.empty()) {
                ArrayList<Integer> item = new ArrayList<>();
                if (!s1.empty()) {
                    while (!s1.empty()) {
                        TreeNode node = s1.pop();
                        item.add(node.val);
                        if (node.left != null) s2.push(node.left);
                        if (node.right != null) s2.push(node.right);
                    }
                } else {
                    while (!s2.empty()) {
                        TreeNode node = s2.pop();
                        item.add(node.val);
                        if (node.right != null) s1.push(node.right);
                        if (node.left != null) s1.push(node.left);
                    }
                }
                res.add(item);
            }
        }
        return res;
    }
}
