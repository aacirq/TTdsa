//
// Created by renxin on 2021/6/25.
//

#include "ttdsa.h"

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        int left = 0, right = rotateArray.size() - 1;
        while (left < right) {
            int m = left + (right - left) / 2;
            if (rotateArray[m] < rotateArray[right]) {
                right = m;
            } else if (rotateArray[m] > rotateArray[right]) {
                left = m + 1;
            } else {
                right--;
            }
        }
        return rotateArray[left];
    }
};

int main() {
    Solution sol;
    vector<int> vec = {3, 4, 5, 1, 2};
    // 1
    cout << sol.minNumberInRotateArray(vec) << endl;
    return 0;
}