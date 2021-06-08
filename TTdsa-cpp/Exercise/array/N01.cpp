//
// Created by renxin on 2021/6/8.
//

#include "ttdsa.h"

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (!array.empty()) {
            int r = 0;
            int c = array[0].size() - 1;
            while (r < array.size() && c >= 0) {
                if (array[r][c] < target) {
                    ++r;
                } else if (target < array[r][c]) {
                    --c;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> array = {{1, 2, 8,  9},
                                 {2, 4, 9,  12},
                                 {4, 7, 10, 13},
                                 {6, 8, 11, 15}};
    // 1
    cout << sol.Find(7, array) << endl;
    // 0
    cout << sol.Find(3, array) << endl;

    return 0;
}
