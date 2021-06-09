//
// Created by renxin on 2021/6/9.
//

#include "ttdsa.h"

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int len = s.size();
        for (auto c : s) {
            if (c == ' ') count++;
        }
        s.resize(len + 2 * count);
        int i = s.size() - 1;
        int j = len - 1;
        while (j < i) {
            if (s[j] != ' ') {
                s[i] = s[j];
                i--;
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 3;
            }
            j--;
        }
        return s;
    }
};

int main() {
    Solution sol;

    // "We%20Are%20Happy"
    cout << sol.replaceSpace("We Are Happy");
    return 0;
}