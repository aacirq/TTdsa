#include "ttdsa.h"

class Solution {
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
        vector<int> res;
        if (num.size() < size || size == 0)
            return res;

        deque<int> d;
        for (int i = 0; i < size; i++) {
            while (!d.empty() && d.back() < num[i]) {
                d.pop_back();
            }
            d.push_back(num[i]);
        }
        res.push_back(d.front());
        for (int i = size; i < num.size(); i++) {
            if (d.front() == num[i - size]) {
                d.pop_front();
            }
            while (!d.empty() && d.back() < num[i]) {
                d.pop_back();
            }
            d.push_back(num[i]);
            res.push_back(d.front());
        }
        return res;
    }
};

int main() {
    {
        Solution sol;
        vector<int> vec = {2, 3, 4, 2, 6, 2, 5, 1};
        // Vector (6): [ 4, 4, 6, 6, 6, 5 ]
        print(sol.maxInWindows(vec, 3));
    }
    {
        Solution sol;
        vector<int> vec = {2, 3};
        // Vector (0): [  ]
        print(sol.maxInWindows(vec, 3));
    }
    {
        Solution sol;
        vector<int> vec = {2, 3, 4, 2, 6, 2, 5, 1};
        // Vector (0): [  ]
        print(sol.maxInWindows(vec, 0));
    }
    return 0;
}