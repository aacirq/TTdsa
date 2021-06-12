//
// Created by renxin on 2021/6/12.
//

#include "ttdsa.h"

class Solution {
public:
    bool isNumeric(string str) {
        if (str.empty())
            return false;
        int ind = 0;
        if (str[0] == '+' || str[0] == '-') {
            ind++;
            if (ind == str.size() || ((str[ind]<'0' || str[ind]>'9') && str[ind] != '.')) return false;
        }
        while (ind < str.size() && str[ind] >= '0' && str[ind] <= '9')
            ind++;
        if (ind == str.size())
            return true;

        if (str[ind] == '.') {
            ind++;
            if (ind == str.size() || str[ind] < '0' || str[ind] > '9') return false;
            while (ind < str.size() && str[ind] >= '0' && str[ind] <= '9')
                ind++;
            if (ind == str.size()) return true;
        }

        if (str[ind] == 'e' || str[ind] == 'E') {
            ind++;
            if (ind < str.size() && (str[ind] == '+' || str[ind] == '-'))
                ind++;
        } else {
            return false;
        }

        if (ind == str.size())
            return false;
        while (ind < str.size() && str[ind] >= '0' && str[ind] <= '9')
            ind++;
        if (ind == str.size()) return true;
        else return false;
    }
};

int main() {
    Solution sol;

    // 全1
    cout << sol.isNumeric("+100") << " "
         << sol.isNumeric("5e2") << " "
         << sol.isNumeric("-123") << " "
         << sol.isNumeric("3.1416") << " "
         << sol.isNumeric("123.45e+6") << " "
         << sol.isNumeric("-.123") << " "
         << sol.isNumeric(".123") << " "
         << sol.isNumeric("-1E-16") << endl;
    // 全0
    cout << sol.isNumeric("12e") << " "
         << sol.isNumeric("1a3.14") << " "
         << sol.isNumeric("+e3") << " "
         << sol.isNumeric("1.2.3") << " "
         << sol.isNumeric("+-5") << " "
         << sol.isNumeric("12e4.3") << endl;
    return 0;
}