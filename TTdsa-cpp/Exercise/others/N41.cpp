#include "ttdsa.h"

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        int slow = 1, fast = 2;
        int cur = slow + fast;
        vector<vector<int>> res;
        while (slow != fast) {
            if (cur == sum) {
                vector<int> item;
                for (int i = slow; i <= fast; i++) {
                    item.push_back(i);
                }
                res.push_back(item);
            }
            if (cur <= sum) {
                fast++;
                cur += fast;
            } else if (sum < cur) {
                cur -= slow;
                slow++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    print(sol.FindContinuousSequence(9));
    print(sol.FindContinuousSequence(0));
    print(sol.FindContinuousSequence(1));
    return 0;
}