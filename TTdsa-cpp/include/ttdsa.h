//
// Created by renxin on 2021/6/8.
//

#ifndef TTDSA_CPP_TTDSA_H
#define TTDSA_CPP_TTDSA_H
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>

using namespace std;

const long tree_null = INT64_MAX;

typedef int64_t tree_type;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // Create List according to a vector<int>
    // 可以直接用initiallizer_list，即construct_list({ 1, 2, 3 })
    // 刷题时用的，没考虑内存释放
    static ListNode *construct(const std::vector<int> &vec);

    // display list
    static void print(const ListNode *node);
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Create Binary Tree according to vector<tree_type>
    //   (tree_null means no node in there)
    //   按照层序遍历方式，但是如果第n层有一个结点时tree_null，那么n+1层对应到这个结点的两个空结点不写(LeetCode和牛客网的方式)
    //   刷题时用的，没考虑内存释放
    // For example:
    // 1. { 3, 9, 20, tree_null, tree_null, 15, 7 }
    //                3
    //               / \
    //              9  20
    //                /  \
    //               15   7
    // 2. { 1, 2, tree_null, 3, tree_null, 4 }
    //                1
    //               /
    //              2
    //             /
    //            3
    //           /
    //          4
    //    : 而不是表示成{ 1, 2, tree_null, 3, tree_null, tree_null, tree_null, 4 }
    //    : 由于2右侧的结点是空，则在写第3层结点时，不写对应到2右侧结点的两个子结点
    // 3. { 1, tree_null, 2, tree_null, 3 }
    //                1
    //                 \
    //                  2
    //                   \
    //                    3
    // 4. { 1, 2, 3, tree_null, 4, 5 }
    //                1
    //              /   \
    //             2     3
    //              \   /
    //               4 5
    // vec is legal, which means that case like { tree_null, tree_null }(illegal) will not exsit
    static TreeNode *construct(const std::vector<tree_type> &vec);

    // display binary tree
    static void print(TreeNode *root);
};

// display vector
// Output like:
//   Vector (<size>): [ <value>, <value>, ... ]
void print(const std::vector<int> &vec);
void print(const std::vector<std::string> &vec);

// display vector of vector
// Output example:
//   Vector of vector (<size>): [
// 	     [ <value>, ... ],
// 	     [ <value>, <value>, ... ],
// 	     [ <value>, <value>, <value>, ... ]
//       ...
//   ]
void print(const std::vector<std::vector<int>> &vec);

#endif //TTDSA_CPP_TTDSA_H
