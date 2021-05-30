package com.aacirq.tree;

public class N18 {
    public static void main(String[] args) {
        N18 sol = new N18();

        TreeNode root = new TreeNode(8);
        root.left = new TreeNode(6);
        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(7);
        root.right = new TreeNode(10);
        root.right.left = new TreeNode(9);
        root.right.right = new TreeNode(11);

        // [8 6 10 5 7 9 11 ]
        TreeNode.print(root);
        // [8 10 6 11 9 7 5 ]
        TreeNode.print(sol.Mirror(root));
    }

    public TreeNode Mirror (TreeNode pRoot) {
        if (pRoot != null) {
            TreeNode leftNode = pRoot.left;
            TreeNode rightNode = pRoot.right;
            pRoot.left = Mirror(rightNode);
            pRoot.right = Mirror(leftNode);
        }
        return pRoot;
    }
}
