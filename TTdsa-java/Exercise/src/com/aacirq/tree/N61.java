package com.aacirq.tree;

import com.aacirq.list.ListNode;

public class N61 {
    public static void main(String[] args) {
        N61 sol = new N61();

        TreeNode root = new TreeNode(8);
        root.left = new TreeNode(6);
        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(7);
        root.right = new TreeNode(10);
        root.right.left = new TreeNode(9);
        root.right.right = new TreeNode(11);

        TreeNode.print(root);
        String serRes = sol.Serialize(root);
        System.out.println(serRes);
        TreeNode.print(sol.Deserialize(serRes));

        TreeNode.print(sol.Deserialize(sol.Serialize(null)));
    }

    String Serialize(TreeNode root) {
        StringBuilder str = new StringBuilder();
        serializePre(str, root);
        return str.toString();
    }

    void serializePre(StringBuilder str, TreeNode node) {
        if (node == null) {
            str.append("#!");
        } else {
            str.append(node.val);
            str.append('!');
            serializePre(str, node.left);
            serializePre(str, node.right);
        }
    }

    TreeNode Deserialize(String str) {
        if (str.length() == 0) {
            return null;
        } else {
            ind = 0;
            return deserializePre(str);
        }
    }

    int ind;

    TreeNode deserializePre(String str) {
        if (ind >= str.length() || str.charAt(ind) == '#') {
            ind += 2;
            return null;
        } else {
            int endInd = ind;
            TreeNode res = new TreeNode(0);
            while (Character.isDigit(str.charAt(endInd))) {
                endInd++;
            }
            res.val = Integer.parseInt(str.substring(ind, endInd));
            ind = endInd + 1;
            res.left = deserializePre(str);
            res.right = deserializePre(str);
            return res;
        }
    }
}
