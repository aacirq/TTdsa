//
// Created by renxin on 2021/8/9.
//

#include "ttdsa.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int occur_times[256] = {0};
        int left = 0, cur = 0;
        int res = 0;
        while (cur < s.size()) {
            occur_times[s[cur]]++;
            while (occur_times[s[cur]] > 1) {
                occur_times[s[left]]--;
                left++;
            }
            res = max(res, cur - left + 1);
            cur++;
        }
        return res;
    }
};

int main() {
    {
        Solution sol;
        // 3
        cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    }
    {
        Solution sol;
        // 1
        cout << sol.lengthOfLongestSubstring("bbbbb") << endl;
    }
    {
        Solution sol;
        // 3
        cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
    }
    {
        Solution sol;
        // 0
        cout << sol.lengthOfLongestSubstring("") << endl;
    }
    return 0;
}