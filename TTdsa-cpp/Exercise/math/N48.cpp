//
// Created by renxin on 2021/6/24.
//

#include "ttdsa.h"

class Solution {
public:
    int Add(int n1, int n2) {
        while (n2 != 0) {
            // 注意这里的类型转换，负数左移是UndefiedBehavior行为
            // unsigned -> int 是inplement-defiened
            int c = static_cast<int>(static_cast<unsigned>(n1 & n2) << 1);
            n1 ^= n2;
            n2 = c;
        }
        return n1;
    }
};

int main() {
    Solution sol;
    // 3
    cout << sol.Add(1, 2) << endl;
    // 1
    cout << sol.Add(-1, 2) << endl;
    return 0;
}