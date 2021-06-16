//
// Created by renxin on 2021/6/16.
//

#include "ttdsa.h"

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution sol;

    sol.push(1);
    sol.push(2);
    sol.push(3);
    // 1
    cout << sol.pop() << endl;
    sol.push(4);
    sol.push(5);
    // 2
    cout << sol.pop() << endl;
    // 3
    cout << sol.pop() << endl;
    // 4
    cout << sol.pop() << endl;
    // 5
    cout << sol.pop() << endl;
    return 0;
}