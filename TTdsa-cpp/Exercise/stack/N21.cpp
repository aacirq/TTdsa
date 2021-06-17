//
// Created by renxin on 2021/6/17.
//

#include "ttdsa.h"

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> s;
        int indPop = 0;
        for (int i : pushV) {
            s.push(i);
            while (!s.empty() && s.top() == popV[indPop]) {
                s.pop();
                indPop++;
            }
        }
        return s.empty();
    }
};

int main() {
    Solution sol;

    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV1 = {4,3,5,1,2};
    vector<int> popV2 = {4,5,3,2,1};

    // 0
    cout << sol.IsPopOrder(pushV, popV1) << endl;
    // 1
    cout << sol.IsPopOrder(pushV, popV2) << endl;

    return 0;
}