#include "ttdsa.h"

class BrowserHistory {
public:
    vector<string> history;
    int cur;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = 0;
    }

    void visit(string url) {
        while (history.size() > cur + 1) {
            history.pop_back();
        }
        history.push_back(url);
        cur++;
    }

    string back(int steps) {
        if (cur - steps >= 0) {
            cur -= steps;
        } else {
            cur = 0;
        }
        return history[cur];
    }

    string forward(int steps) {
        if (cur + steps < history.size()) {
            cur += steps;
        } else {
            cur = history.size() - 1;
        }
        return history[cur];
    }
};

int main() {
    return 0;
}