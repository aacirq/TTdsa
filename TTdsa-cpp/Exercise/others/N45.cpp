#include "ttdsa.h"

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        int flags[14] = {0};
        int max_num = 0;
        int min_num = 14;
        for (int i : numbers) {
            if (i != 0) {
                if (flags[i] != 1) {
                    flags[i] = 1;
                    max_num = std::max(max_num, i);
                    min_num = std::min(min_num, i);
                } else {
                    return false;
                }
            }
        }
        return (max_num - min_num) < 5;
    }
};

int main() {
    Solution sol;
    {
        vector<int> vec = {6, 0, 2, 0, 4};
        // true
        cout << sol.IsContinuous(vec) << endl;
    }
    {
        vector<int> vec = {0, 3, 2, 6, 4};
        // true
        cout << sol.IsContinuous(vec) << endl;
    }
    {
        vector<int> vec = {1, 0, 0, 1, 0};
        // false
        cout << sol.IsContinuous(vec) << endl;
    }
    {
        vector<int> vec = {13, 12, 11, 0, 1};
        // false
        cout << sol.IsContinuous(vec) << endl;
    }
    return 0;
}