package com.aacirq.tree;

public class N04 {
    public static void main(String[] args) {
        N04 sol = new N04();

        int[] pre = {1, 2, 3, 4, 5, 6, 7};
        int[] in = {3, 2, 4, 1, 6, 5, 7};
        TreeNode node = sol.reConstructBinaryTree(pre, in);
        // [1 2 5 3 4 6 7 ]
        TreeNode.print(node);
    }

    int[] pre;
    int[] in;

    public TreeNode reConstructBinaryTree(int[] pre, int[] in) {
        if (pre.length == 0)
            return null;

        // 避免数组的频繁复制
        this.pre = new int[pre.length];
        this.in = new int[in.length];
        for (int i = 0; i < pre.length; i++) {
            this.pre[i] = pre[i];
            this.in[i] = in[i];
        }

        return fun(0, 0, in.length - 1);
    }

    public TreeNode fun(int preInd, int inLeft, int inRight) {
        if (inLeft > inRight)
            return null;
        int midInd = inLeft;
        while (in[midInd] != pre[preInd])
            midInd++;
        TreeNode res = new TreeNode(pre[preInd]);
        res.left = fun(preInd + 1, inLeft, midInd - 1);
        res.right = fun(preInd + midInd - inLeft + 1, midInd + 1, inRight);
        return res;
    }
}
