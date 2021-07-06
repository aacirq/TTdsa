#include "ttdsa.h"
#include <climits>

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        long res = LONG_MIN;
        long cur = 0;
        for (int i = 0; i < array.size(); i++) {
            cur += array[i];
            if (cur > res) {
                res = cur;
            }
            if (cur < 0) {
                cur = 0;
            }
        }
        return res;
    }
};

int main() {
    {
        Solution sol;
        vector<int> vec = {1,-2,3,10,-4,7,2,-5};
        cout << sol.FindGreatestSumOfSubArray(vec) << endl;
    }
    {
        Solution sol;
        vector<int> vec = {-1, -2, -3, -4, -5};
        cout << sol.FindGreatestSumOfSubArray(vec) << endl;
    }

    return 0;
}