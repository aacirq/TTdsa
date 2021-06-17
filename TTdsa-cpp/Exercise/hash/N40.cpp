//
// Created by renxin on 2021/6/17.
//

#include "ttdsa.h"

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int> &array) {
        unordered_map<int, bool> hash;
        for (int i : array) {
            if (hash.find(i) == hash.end()) {
                hash[i] = true;
            } else {
                hash[i] = false;
            }
        }

        vector<int> res;
        for (auto p : hash) {
            if (p.second) {
                res.push_back(p.first);
            }
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