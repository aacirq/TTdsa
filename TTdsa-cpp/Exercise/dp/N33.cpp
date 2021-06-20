//
// Created by renxin on 2021/6/20.
//

#include "ttdsa.h"

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index == 0) return 0;
        int vec[index];
        vec[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < index; i++) {
            int n2 = 2 * vec[p2], n3 = 3 * vec[p3], n5 = 5 * vec[p5];
            vec[i] = min(min(n2, n3), n5);
            if (vec[i] == n2) p2++;
            if (vec[i] == n3) p3++;
            if (vec[i] == n5) p5++;
        }
        return vec[index - 1];
    }
};

int main() {
    Solution sol;

    for (int i = 1; i < 10; i++) {
        cout << sol.GetUglyNumber_Solution(i) << endl;
    }

    return 0;
}