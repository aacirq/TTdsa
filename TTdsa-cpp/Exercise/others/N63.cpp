#include "ttdsa.h"

class Solution {
public:
    priority_queue<int, vector<int>, less<int>> small;
    priority_queue<int, vector<int>, greater<int>> large;

    void Insert(int num) {
        if (small.size() != large.size()) {
            small.push(num);
            int tnum = small.top();
            small.pop();
            large.push(tnum);
        } else {
            large.push(num);
            int tnum = large.top();
            large.pop();
            small.push(tnum);
        }
    }

    double GetMedian() {
        if (small.size() != large.size()) {
            return static_cast<double>(small.top());
        } else {
            return (static_cast<double>(small.top()) + static_cast<double>(large.top())) / 2;
        }
    }
};

int main() {
    Solution sol;

    sol.Insert(5);
    // 5.00
    cout << sol.GetMedian() << endl;
    sol.Insert(2);
    // 3.50
    cout << sol.GetMedian() << endl;
    sol.Insert(3);
    // 3.00
    cout << sol.GetMedian() << endl;
    sol.Insert(4);
    // 3.50
    cout << sol.GetMedian() << endl;
    sol.Insert(1);
    // 3.00
    cout << sol.GetMedian() << endl;
    sol.Insert(6);
    // 3.50
    cout << sol.GetMedian() << endl;
    sol.Insert(7);
    // 4.00
    cout << sol.GetMedian() << endl;
    sol.Insert(0);
    // 3.50
    cout << sol.GetMedian() << endl;
    sol.Insert(8);
    // 4.00
    cout << sol.GetMedian() << endl;
    return 0;
}