#include "ttdsa.h"

class Solution {
public:
    bool hasPath(vector<vector<char>> &matrix, string word) {
        if (word.empty() || matrix.empty()) {
            return false;
        }
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                if (check(matrix, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool check(vector<vector<char>> &mat, const string &word, 
               int r, int c, int ind) {
        if (r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size() || word[ind] != mat[r][c])
            return false;
        if (ind == word.size() - 1)
            return true;
        mat[r][c] = '\0';
        ind;
        bool res = check(mat, word, r+1, c, ind+1) || 
                   check(mat, word, r-1, c, ind+1) || 
                   check(mat, word, r, c+1, ind+1) || 
                   check(mat, word, r, c-1, ind+1);
        mat[r][c] = word[ind];
        return res;
    }
};

int main() {
    {
        Solution sol;
        vector<vector<char>> mat = {{'a', 'b', 'c', 'e'}, 
                                    {'s', 'f', 'c', 's'}, 
                                    {'a', 'd', 'e', 'e'}};
        string word = "abcced";
        // 1
        cout << sol.hasPath(mat, word) << endl;
    }
    {
        Solution sol;
        vector<vector<char>> mat = {{'a', 'b', 'c', 'e'}, 
                                    {'s', 'f', 'c', 's'}, 
                                    {'a', 'd', 'e', 'e'}};
        string word = "abcb";
        // 0
        cout << sol.hasPath(mat, word) << endl;
    }
    {
        Solution sol;
        vector<vector<char>> mat = {{'A', 'B', 'C', 'E', 'H', 'J', 'I', 'G'}, 
                                    {'S', 'F', 'C', 'S', 'L', 'O', 'P', 'Q'}, 
                                    {'A', 'D', 'E', 'E', 'M', 'N', 'O', 'E'}, 
                                    {'A', 'D', 'I', 'D', 'E', 'J', 'F', 'M'}, 
                                    {'V', 'C', 'E', 'I', 'F', 'G', 'G', 'S'}};
        string word = "SGGFIECVAASABCEHJIGQEM";
        // string word = "SGGFIECVAAS";
        // string word = "VAASABCEHJIGQEM";
        // 1
        cout << sol.hasPath(mat, word) << endl;
    }

    return 0;
}