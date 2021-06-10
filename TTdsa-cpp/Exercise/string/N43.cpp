//
// Created by renxin on 2021/6/10.
//

#include "ttdsa.h"

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.size() == 0)
            return str;
        n %= str.size();
        return str.substr(n, str.size() - n) + str.substr(0, n);
    }
};

int main() {
    Solution sol;

    // XYZdefabc
    cout << sol.LeftRotateString("abcXYZdef", 3) << endl;
    // a
    cout << sol.LeftRotateString("a", 3) << endl;
    // <empty line>
    cout << sol.LeftRotateString("", 3) << endl;

    return 0;
}