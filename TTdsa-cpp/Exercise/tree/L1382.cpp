//
// Created by renxin on 2021/8/9.
//

#include "ttdsa.h"

class Solution {
private:
    vector<TreeNode *> arr;
public:
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        return build(0, arr.size() - 1);
    }

private:
    TreeNode *build(int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (right - left) / 2 + left;
        TreeNode *node = arr[mid];
        node->left = build(left, mid - 1);
        node->right = build(mid + 1, right);
        return node;
    }

    void traverse(TreeNode *root) {
        if (root == nullptr)
            return;
        traverse(root->left);
        arr.push_back(root);
        traverse(root->right);
    }
};

int main() {
    {
        Solution sol;
        TreeNode *root = TreeNode::construct({1,tree_null,15,14,17,7,tree_null,tree_null,tree_null,2,12,tree_null,3,9,tree_null,tree_null,tree_null,tree_null,11});
        TreeNode *res_root = sol.balanceBST(root);
        TreeNode::print(res_root);
        // 结果不唯一，检测是否平衡即可
    }
    {
        Solution sol;
        TreeNode *root = TreeNode::construct({1,tree_null,2,tree_null,3,tree_null,4,tree_null,tree_null});
        TreeNode *res_root = sol.balanceBST(root);
        TreeNode::print(res_root);
        // 结果不唯一，检测是否平衡即可
    }
    return 0;
}