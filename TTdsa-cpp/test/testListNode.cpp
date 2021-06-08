//
// Created by renxin on 2021/6/8.
//

#include "ttdsa.h"

int main() {
    ListNode *node1 = ListNode::construct({});
    // 1
    cout << (node1 == nullptr) << endl;
    // List: null
    ListNode::print(node1);

    cout << "============================" << endl;
    ListNode *node2 = ListNode::construct({1, 2, 3});
    // 1
    cout << (node2 != nullptr) << endl;
    // 1 -> 2 -> 3
    cout << node2->val << " -> " << node2->next->val << " -> " << node2->next->next->val << endl;
    // List: 1 -> 2 -> 3
    ListNode::print(node2);

    return 0;
}