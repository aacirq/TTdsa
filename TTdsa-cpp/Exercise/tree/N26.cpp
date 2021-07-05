#include "ttdsa.h"

class Solution {
public:
    TreeNode *Convert(TreeNode *root) {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        return head;
    }

private:
    TreeNode *pre = nullptr;
    TreeNode *head = nullptr;

    void dfs(TreeNode *cur) {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        if (pre != nullptr) {
            pre->right = cur;
        } else {
            head = cur;
        }
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};

void printTreeList(TreeNode *node) {
    while (node != nullptr) {
        cout << node->val << " ->";
        node = node->right;
    }
    cout << "null" << endl;
}

int main() {
    {
        Solution sol;
        TreeNode *root = TreeNode::construct({10,6,14,4,8,12,16});
        printTreeList(sol.Convert(root));
    }

    {
        Solution sol;
        TreeNode *root = TreeNode::construct({5,4,tree_null,3,tree_null,2,tree_null,1});
        printTreeList(sol.Convert(root));
    }

    {
        Solution sol;
        TreeNode *root = TreeNode::construct({tree_null});
        printTreeList(sol.Convert(root));
    }
    return 0;
}