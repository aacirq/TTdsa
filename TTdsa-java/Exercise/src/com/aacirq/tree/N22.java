package com.aacirq.tree;

import java.util.ArrayList;
import java.util.LinkedList;

public class N22 {
    public static void main(String[] args) {
        N22 sol = new N22();

        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(4);
        root.left.left = new TreeNode(3);
        root.left.left.left = new TreeNode(2);
        root.left.left.left.left = new TreeNode(1);

        // [5, 4, 3, 2, 1]
        System.out.println(sol.PrintFromTopToBottom(root));
    }

    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
        ArrayList<Integer> res = new ArrayList<>();
        LinkedList<TreeNode> list = new LinkedList<>();
        if (root == null)
            return res;
        list.add(root);
        while (list.size() != 0) {
            TreeNode node = list.remove();
            res.add(node.val);
            if (node.left != null)
                list.add(node.left);
            if (node.right != null)
                list.add(node.right);
        }
        return res;
    }
}
