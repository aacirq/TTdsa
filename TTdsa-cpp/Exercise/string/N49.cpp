//
// Created by renxin on 2021/6/11.
//

#include "ttdsa.h"

class Solution {
public:
    int StrToInt(string str) {
        int res = 0;
        int sign;
        if (str.size() == 0)
            return 0;
        int ind = 0;
        if (str[ind] == '-') {
            sign = -1;
            ind++;
        } else if (str[ind] == '+') {
            sign = 1;
            ind++;
        }
        while (ind < str.size()) {
            if (str[ind] < '0' || str[ind] > '9')
                return 0;
            res = res * 10 + str[ind] - '0';
            ind++;
        }
        return sign * res;
    }
};

int main() {
    Solution sol;

    // 2147483647
    cout << sol.StrToInt("+2147483647") << endl;
    return 0;
}