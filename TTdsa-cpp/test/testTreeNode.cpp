//
// Created by renxin on 2021/6/8.
//

#include "ttdsa.h"

int main() {
    TreeNode *node1 = TreeNode::construct({});
    cout << "======1=====================" << endl;
    // 1
    cout << (node1 == nullptr) << endl;
    // Binary tree:
    // <empty>
    TreeNode::print(node1);

    cout << "======2=====================" << endl;
    TreeNode *node2 = TreeNode::construct({ 3, 9, 20, tree_null, tree_null, 15, 7 });
    // 1
    cout << (node2 != nullptr) << endl;
    // Binary tree:
    // 3
    // 9 20
    // * * 15 7
    TreeNode::print(node2);

    cout << "======3=====================" << endl;
    TreeNode *node3 = TreeNode::construct({ 1, 2, tree_null, 3, tree_null, 4 });
    // 1
    cout << (node3 != nullptr) << endl;
    // Binary tree:
    // 1
    // 2 *
    // 3 * * *
    // 4 * * * * * * *
    TreeNode::print(node3);

    cout << "======4=====================" << endl;
    TreeNode *node4 = TreeNode::construct({ 1, tree_null, 2, tree_null, 3 });
    // 1
    cout << (node4 != nullptr) << endl;
    // Binary tree:
    // 1
    // * 2
    // * * * 3
    TreeNode::print(node4);

    cout << "======5=====================" << endl;
    TreeNode *node5 = TreeNode::construct({ 1, 2, 3, tree_null, 4, 5 });
    // 1
    cout << (node5 != nullptr) << endl;
    // Binary tree:
    // 1
    // 2 3
    // * 4 5 *
    TreeNode::print(node5);

    return 0;
}