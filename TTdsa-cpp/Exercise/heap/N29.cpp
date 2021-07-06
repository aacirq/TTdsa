#include "ttdsa.h"

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.size() < k)
            return res;
        quickSort(input, 0, input.size() - 1);
        res.assign(input.begin(), input.begin() + k);
        return res;
    }

private:
    void quickSort(vector<int> &input, int left, int right) {
        if (left >= right)
            return;
        int i = left, j = right;
        while (i < j) {
            if (input[j] >= input[left]) {
                j--;
            } else if (input[i] <= input[left]) {
                i++;
            } else {
                using std::swap;
                swap(input[i], input[j]);
            }
        }
        swap(input[left], input[j]);
        quickSort(input, left, i - 1);
        quickSort(input, i + 1, right);
    }
};

int main() {
    Solution sol;
    vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    print(sol.GetLeastNumbers_Solution(input, 4));

    return 0;
}