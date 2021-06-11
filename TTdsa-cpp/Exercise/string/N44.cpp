//
// Created by renxin on 2021/6/11.
//

#include "ttdsa.h"

class Solution {
public:
    string ReverseSentence(string str) {
        if (str.size() == 0)
            return str;
        string res(str.size(), ' ');
        int ind = 0;
        int eInd = str.size() - 1;
        int sInd = eInd;
        while (ind < res.size()) {
            while (sInd >= 0 && str[sInd] != ' ')
                --sInd;
            for (int i = sInd + 1; i <= eInd; i++) {
                res[ind++] = str[i];
            }
            ind++;
            eInd = sInd - 1;
            sInd = eInd;
        }
        return res;
    }
};

int main() {
    Solution sol;

    // "I am a nowcoder."
    cout << "\"" << sol.ReverseSentence("nowcoder. a am I") << "\"" << endl;
    // ""
    cout << "\"" << sol.ReverseSentence("") << "\"" << endl;
    // " "
    cout << "\"" << sol.ReverseSentence(" ") << "\"" << endl;
    // "  "
    cout << "\"" << sol.ReverseSentence("  ") << "\"" << endl;
    return 0;
}