#include "ttdsa.h"

class Solution {
public:
    int jumpFloor(int number) {
        int n1 = 1;
        int n2 = 1;
        for (int i = 2; i <= number; i++) {
            int tmp = n2;
            n2 += n1;
            n1 = tmp;
        }
        return n2;
    }
};

int main() {
    Solution sol;
    
    for (int i = 1; i < 10; i++) {
        cout << i << ":\t" << sol.jumpFloor(i) << endl;
    }

    return 0;
}