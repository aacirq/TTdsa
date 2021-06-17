//
// Created by renxin on 2021/6/17.
//

#include "ttdsa.h"

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int> &array) {
        int m = 0;
        for (int i : array) {
            m ^= i;
        }

        m |= (m << 1);
        m |= (m << 2);
        m |= (m << 4);
        m |= (m << 8);
        m |= (m << 16);
        m = (~m) + 1;

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