#include "ttdsa.h"

class Solution {
public:
    int rectCover(int number) {
        if (number == 0)
            return 0;
        int n1 = 1, n2 = 1;
        for (int i = 2; i <= number; i++) {
            int s = n1 + n2;
            n1 = n2;
            n2 = s;
        }
        return n2;
    }
};

int main() {
    Solution sol;
    for (int i = 0; i <= 10; i ++) {
        cout << i << "\t" << sol.rectCover(i) << endl;
    }
    return 0;
}