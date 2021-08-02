#include "ttdsa.h"

class Solution {
public:
    int left_value(int n_layer) {
        if (n_layer % 2 == 1) {
            return (1 << (n_layer - 1));
        } else {
            return ((1 << n_layer) - 1);
        }
    }
    vector<int> pathInZigZagTree(int label) {
        int n_layer = 1;
        int n = 2;
        while (label >= n) {
            n <<= 1;
            n_layer++;
        }

        vector<int> res(n_layer, 0);
        res[n_layer - 1] = label;
        int left = left_value(n_layer);
        while (n_layer > 1) {
            n_layer--;
            int cur_left = left_value(n_layer);
            label = cur_left + (left-label)/2;
            left = cur_left;
            res[n_layer - 1] = label;
        }
        return res;
    }
};

int main() {
    {
        Solution sol;
        // Vector (4): [ 1, 3, 4, 14 ]
        print(sol.pathInZigZagTree(14));
    }
    {
        Solution sol;
        // Vector (5): [ 1, 2, 6, 10, 26 ]
        print(sol.pathInZigZagTree(26));
    }
    return 0;
}