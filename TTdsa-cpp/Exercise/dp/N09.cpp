#include "ttdsa.h"

#include <cmath>

class Solution {
public:
    int jumpFloorII(int number) {
        return 1 << (number - 1);
    }
};

int main() {
    Solution sol;

    for (int i = 1; i < 10; i++) {
        cout << i << ":\t" << sol.jumpFloorII(i) << endl;\
    }
    return 0;
}