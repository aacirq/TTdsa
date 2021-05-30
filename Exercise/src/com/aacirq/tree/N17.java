package com.aacirq.tree;

import java.util.HashSet;

public class N17 {
    public static void main(String[] args) {
        N17 sol = new N17();

        TreeNode root1 = new TreeNode(8);
        root1.left = new TreeNode(8);
        root1.left.left = new TreeNode(9);
        root1.left.left.left = new TreeNode(2);
        root1.left.left.left.left = new TreeNode(5);

        TreeNode root2 = new TreeNode(8);
        root2.left = new TreeNode(9);
        root2.left.left = new TreeNode(2);

        System.out.println(sol.HasSubtree(root1, root2));
    }

    public boolean HasSubtree(TreeNode root1, TreeNode root2) {
        if (root2 == null)
            return false;
        return fun(root1, root2);
    }

    public boolean fun(TreeNode root1, TreeNode root2) {
        // check root2 is not null before invoke this function
        if (root1 == null) {
            return false;
        } else {
            return SameTree(root1, root2) || fun(root1.left, root2) || fun(root1.right, root2);
        }
    }

    public boolean SameTree(TreeNode root1, TreeNode root2) {
        if (root2 == null) {
            return true;
        } else {
            if (root1 == null) return false;
            else return (root1.val == root2.val)
                    && SameTree(root1.left, root2.left)
                    && SameTree(root1.right, root2.right);
        }
    }
}
