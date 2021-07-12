#include "ttdsa.h"

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        row = rows;
        col = cols;
        thres = threshold;
        vector<vector<int>> mat(rows, vector<int>(cols));
        return fun(mat, 0, 0, 0, 0);
    }

private:
    int row;
    int col;
    int thres;

    int fun(vector<vector<int>> &mat, int r, int c, int sumr, int sumc) {
        if (r < 0 || r >= row || c < 0 || c >= col || mat[r][c] == 1 || sumr + sumc > thres) {
            return 0;
        }
        mat[r][c] = 1;
        return 1 + fun(mat, r+1, c, ((r+1)%10 != 0) ? (sumr + 1) : (sumr - 8), sumc) +
                   fun(mat, r, c+1, sumr, ((c+1)%10 != 0) ? (sumc + 1) : (sumc - 8));
    }
};

int main() {
    {
        Solution sol;
        // 3
        cout << sol.movingCount(1, 2, 3) << endl;
    }
    {
        Solution sol;
        // 1
        cout << sol.movingCount(0, 1, 3) << endl;
    }
    {
        Solution sol;
        // 29
        cout << sol.movingCount(10, 1, 100) << endl;
    }
    {
        Solution sol;
        // 21
        cout << sol.movingCount(5, 10, 10) << endl;
    }

    return 0;
}