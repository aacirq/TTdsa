package com.aacirq.tree;

public class N39 {
    public static void main(String[] args) {
        N39 sol = new N39();

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right = new TreeNode(3);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        // true
        System.out.println(sol.IsBalanced_Solution(root));
    }

    public boolean IsBalanced_Solution(TreeNode root) {
        return dfs(root) != -1;
    }

    public int dfs(TreeNode root) {
        if (root == null)
            return 0;
        int leftHeight = dfs(root.left);
        int rightHeight = dfs(root.right);
        if (leftHeight == -1 || rightHeight == -1)
            return -1;

        int delta = leftHeight - rightHeight;
        if (delta > 1 || delta < -1) {
            return -1;
        } else {
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }
}
