//
// Created by renxin on 2021/6/17.
//

#include "ttdsa.h"

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int> &array) {
        int x = 0;
        for (int i : array) {
            x ^= i;
        }
        int m = 1;
        while ((m & x) == 0) {
            m <<= 1;
        }
        vector<int> res(2, 0);
        for (int i : array) {
            if (i & m) res[0] ^= i;
            else res[1] ^= i;
        }
        if (res[0] > res[1]) {
            using std::swap;
            swap(res[0], res[1]);
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> array = {1, 4, 1, 6};
    print(sol.FindNumsAppearOnce(array));

    return 0;
}