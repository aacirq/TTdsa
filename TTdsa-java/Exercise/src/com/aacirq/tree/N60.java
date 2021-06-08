package com.aacirq.tree;

import java.util.ArrayList;
import java.util.LinkedList;

public class N60 {
    public static void main(String[] args) {
        N60 sol = new N60();

        TreeNode pRoot = new TreeNode(8);
        pRoot.left = new TreeNode(6);
        pRoot.left.left = new TreeNode(5);
        pRoot.left.right = new TreeNode(7);
        pRoot.right = new TreeNode(10);
        pRoot.right.left = new TreeNode(9);
        pRoot.right.right = new TreeNode(11);

        // [[8], [6, 10], [5, 7, 9, 11]]
        System.out.println(sol.Print(pRoot));
    }

    ArrayList<ArrayList<Integer>> Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        if (pRoot != null) {
            LinkedList<TreeNode> list = new LinkedList<>();
            list.add(pRoot);
            while (list.size() != 0) {
                int sz = list.size();
                ArrayList<Integer> aLine = new ArrayList<>();
                while (sz-- != 0) {
                    TreeNode tmpNode = list.remove();
                    aLine.add(tmpNode.val);
                    if (tmpNode.left != null) list.add(tmpNode.left);
                    if (tmpNode.right != null) list.add(tmpNode.right);
                }
                res.add(aLine);
            }
        }
        return res;
    }
}
