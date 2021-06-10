//
// Created by renxin on 2021/6/10.
//

#include "ttdsa.h"

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, bool> m;
        for (char & c : str) {
            m[c] = (m.find(c) == m.end());
        }
        for (int i = 0; i < str.size(); i++) {
            if (m[str[i]])
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // 4
    cout << sol.FirstNotRepeatingChar("google") << endl;

    // -1
    cout << sol.FirstNotRepeatingChar("") << endl;

    return 0;
}