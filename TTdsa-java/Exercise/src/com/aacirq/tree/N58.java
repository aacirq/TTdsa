package com.aacirq.tree;

public class N58 {
    public static void main(String[] args) {
        N58 sol = new N58();

        TreeNode root1 = new TreeNode(8);
        root1.left = new TreeNode(6);
        root1.left.left = new TreeNode(5);
        root1.left.right = new TreeNode(7);
        root1.right = new TreeNode(6);
        root1.right.left = new TreeNode(7);
        root1.right.right = new TreeNode(5);

        // true
        System.out.println(sol.isSymmetrical(root1));

        TreeNode root2 = new TreeNode(8);
        root2.left = new TreeNode(6);
        root2.left.left = new TreeNode(5);
        root2.left.right = new TreeNode(7);
        root2.right = new TreeNode(9);
        root2.right.left = new TreeNode(7);
        root2.right.right = new TreeNode(5);

        // false
        System.out.println(sol.isSymmetrical(root2));
    }

    boolean isSymmetrical(TreeNode pRoot) {
        if (pRoot == null)
            return true;
        else
            return fun(pRoot.left, pRoot.right);
    }

    boolean fun(TreeNode node1, TreeNode node2) {
        if (node1 == null) {
            return node2 == null;
        } else {
            if (node2 == null) {
                return false;
            } else {
                return node1.val == node2.val
                        && fun(node1.left, node2.right)
                        && fun(node1.right, node2.left);
            }
        }
    }
}
