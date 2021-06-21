//
// Created by renxin on 2021/6/21.
//

#include "ttdsa.h"

class Solution {
public:
    int res = 0;
    int Sum_Solution(int n) {
        bool b = (n > 0) && (Sum_Solution(n - 1) > 0);
        res += n;
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.Sum_Solution(5) << endl;
    return 0;
}