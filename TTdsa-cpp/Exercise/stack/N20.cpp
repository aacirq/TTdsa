//
// Created by renxin on 2021/6/16.
//

#include "ttdsa.h"

class Solution {
private:
    stack<int> valStack;
    stack<int> minStack;
public:
    void push(int value) {
        valStack.push(value);
        if (minStack.empty()) {
            minStack.push(value);
        } else {
            if (value < minStack.top()) {
                minStack.push(value);
            } else {
                minStack.push(minStack.top());
            }
        }
    }

    void pop() {
        valStack.pop();
        minStack.pop();
    }

    int top() {
        return valStack.top();
    }

    int min() {
        return minStack.top();
    }
};

int main() {
    Solution sol;
    sol.push(-1);
    sol.push(2);
    // -1
    cout << sol.min() << endl;
    // 2
    cout << sol.top() << endl;
    sol.pop();
    sol.push(1);
    // 1
    cout << sol.top() << endl;
    // -1
    cout << sol.min() << endl;
    return 0;
}