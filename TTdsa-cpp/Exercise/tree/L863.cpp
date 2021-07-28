#include "ttdsa.h"

class Solution {
private:
    vector<int> res;
    unordered_map<int, TreeNode *> parent;
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        parent[root->val] = nullptr;
        findParent(root);
        dfs(target, target, 0, k);
        return res;
    }

private:
    void findParent(TreeNode *root) {
        if (root->left != nullptr) {
            parent[root->left->val] = root;
            findParent(root->left);
        }
        if (root->right != nullptr) {
            parent[root->right->val] = root;
            findParent(root->right);
        }
    }

    void dfs(TreeNode *node, TreeNode *from, int depth, int k) {
        if (node == nullptr) {
            return;
        } else if (depth == k) {
            res.push_back(node->val);
            return;
        }
        if (node->left != from) {
            dfs(node->left, node, depth+1, k);
        }
        if (node->right != from) {
            dfs(node->right, node, depth+1, k);
        }
        if (parent[node->val] != from) {
            dfs(parent[node->val], node, depth+1, k);
        }
    }
};

int main() {
    {
        Solution sol;
        TreeNode *root = TreeNode::construct({3,5,1,6,2,0,8,tree_null,tree_null,7,4});
        TreeNode *target = root->left;
        int k = 2;
        // Vector (3): [ 7, 4, 1 ]
        print(sol.distanceK(root, target, k));
    }
    {
        Solution sol;
        TreeNode *root = TreeNode::construct({0,1,tree_null,3,2});
        TreeNode *target = root->left->right;
        int k = 1;
        // Vector (1): [ 1 ]
        print(sol.distanceK(root, target, k));
    }
}