//
// Created by renxin on 2021/6/12.
//

#include "ttdsa.h"

class Solution {
public:
    queue<char> q;
    unordered_map<char, int> s;

    //Insert one char from stringstream
    void Insert(char ch) {
        if (s.find(ch) == s.end()) {
            q.push(ch);
        }
        s[ch]++;
    }

    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while (!q.empty() && s[q.front()] > 1) {
            q.pop();
        }
        if (q.empty())
            return '#';
        else
            return q.front();
    }

};

int main() {
    Solution sol;

    // gggll
    sol.Insert('g');
    cout << sol.FirstAppearingOnce();
    sol.Insert('o');
    cout << sol.FirstAppearingOnce();
    sol.Insert('o');
    cout << sol.FirstAppearingOnce();
    sol.Insert('g');
    sol.Insert('l');
    cout << sol.FirstAppearingOnce();
    sol.Insert('e');
    cout << sol.FirstAppearingOnce();

    return 0;
}