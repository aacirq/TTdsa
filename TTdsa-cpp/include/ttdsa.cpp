//
// Created by renxin on 2021/6/8.
//

#include "ttdsa.h"

ListNode *ListNode::construct(const std::vector<int> &vec) {
    ListNode *head = new ListNode();
    ListNode *node = head;
    for (auto itr = vec.begin(), itr_e = vec.end(); itr != itr_e; ++itr) {
        node->next = new ListNode(*itr);
        node = node->next;
    }
    node = head;
    head = head->next;
    delete node;
    return head;
}

TreeNode *TreeNode::construct(const std::vector<tree_type> &vec) {
    if (vec.empty()) return nullptr;
    if (vec[0] == tree_null) return nullptr;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode( static_cast<int>(vec[0]));
    q.push(root);
    int ind = 1;
    while (ind < vec.size()) {
        if (vec[ind] != tree_null) {
            q.front()->left = new TreeNode(static_cast<int>(vec[ind]));
            q.push(q.front()->left);
        }
        ++ind;
        if (ind < vec.size() && vec[ind] != tree_null) {
            q.front()->right = new TreeNode(static_cast<int>(vec[ind]));
            q.push(q.front()->right);
        }
        ++ind;
        q.pop();
    }
    return root;
}

void ListNode::print(const ListNode *node) {
    cout << "List: ";
    if (!node) {
        cout << "null" << endl;
        return;
    }
    while(node->next) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << node->val << endl;
}

static inline void print_a_vector(const std::vector<int> &vec) {
    cout << "[ ";
    auto itr = vec.begin(), itr_e = vec.end();
    if (itr != itr_e) {
        cout << *itr;
        for (++itr; itr != itr_e; ++itr)
            cout << ", " << *itr;
    }
    cout << " ]";
}

void print(const std::vector<int> &vec) {
    cout << "Vector (" << vec.size() << "): ";
    print_a_vector(vec);
    cout << endl;
}

void print(const std::vector<std::string> &vec) {
    cout << "Vector (" << vec.size() << "): ";
    cout << "[ ";
    auto itr = vec.begin(), itr_e = vec.end();
    if (itr != itr_e) {
        cout << *itr;
        for (++itr; itr != itr_e; ++itr)
            cout << ", " << *itr;
    }
    cout << " ]";
    cout << endl;
}

void print(const std::vector<std::vector<int>> &vec) {
    cout << "Vector of vector (" << vec.size() << "): [" << endl;
    auto itr = vec.begin(), itr_e = vec.end();
    if (itr != itr_e) {
        cout << "\t";
        print_a_vector(*itr);
        for (++itr; itr != itr_e; ++itr) {
            cout << "," << endl << "\t";
            print_a_vector(*itr);
        }
    }
    cout << endl << "]" << endl;
}

void TreeNode::print(TreeNode *root) {
    cout << "Binary tree:" << endl;
    if (root == nullptr) {
        cout << "<empty>" << endl;
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    int sz;
    bool all_null = false;
    while (!all_null) {
        vector<TreeNode *> line;
        sz = q.size();
        all_null = true;
        for (int i = 0; i < sz; ++i) {
            if (q.front() != nullptr) {
                all_null = false;
                q.push(q.front()->left);
                q.push(q.front()->right);
            } else {
                q.push(nullptr);
                q.push(nullptr);
            }
            line.push_back(q.front());
            q.pop();
        }
        if (!all_null) {
            for (auto n : line) {
                if (n != nullptr)
                    cout << n->val << " ";
                else
                    cout << "* ";
            }
            cout << endl;
        }
    }
}