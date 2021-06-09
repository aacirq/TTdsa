//
// Created by renxin on 2021/6/9.
//

#include "ttdsa.h"

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> vec;
        if (!str.empty())
            perm(str, 0, vec);
        sort(vec.begin(), vec.end());
        return vec;
    }

    void perm(string &str, int ind, vector<string> &vec) {
        if (ind == str.size() - 1) {
            vec.push_back(str);
            return;
        }

        unordered_set<char> s;
        for (int i = ind; i < str.size(); i++) {
            if (s.find(str[i]) != s.end())
                continue;
            using std::swap;
            s.insert(str[i]);
            swap(str[i], str[ind]);
            perm(str, ind + 1, vec);
            swap(str[i], str[ind]);
        }
    }
};

int main() {
    Solution sol;

    // Vector (2): [ ab, ba ]
    print(sol.Permutation("ab"));

    // Vector (1): [ aaa ]
    print(sol.Permutation("aaa"));

    // Vector (1): [ aaa ]
    print(sol.Permutation("baaa"));

    // Vector (14): [ aabd, aadb, abad, abda, adab, adba, baad, bada, bdaa, daab, daab, daba, daba, dbaa ]
    print(sol.Permutation("abad"));
    return 0;
}