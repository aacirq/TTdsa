package com.aacirq.tree;

import java.util.ArrayList;
import java.util.Arrays;

public class N24 {
    public static void main(String[] args) {
        N24 sol = new N24();

        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(5);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(7);
        root.right = new TreeNode(12);

        // [[10, 5, 7], [10, 12]]
        System.out.println(sol.FindPath(root, 22));

        // []
        System.out.println(sol.FindPath(root, 15));
    }

    ArrayList<ArrayList<Integer>> res;

    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root, int target) {
        res = new ArrayList<>();
        fun(root, target, new ArrayList<>());
        return res;
    }

    public void fun(TreeNode root, int target, ArrayList<Integer> path) {
        if (target < 0 || root == null)
            return;
        if (root.left == null && root.right == null) {
            if (target == root.val) {
                ArrayList<Integer> thisPath = new ArrayList<>(path);
                thisPath.add(root.val);
                res.add(thisPath);
            }
        } else {
            path.add(root.val);
            fun(root.left, target - root.val, path);
            fun(root.right, target - root.val, path);
            path.remove(path.size() - 1);
        }
    }
}
