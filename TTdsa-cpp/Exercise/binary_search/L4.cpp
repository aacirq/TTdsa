//
// Created by renxin on 2021/8/10.
//

#include "ttdsa.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2 == 1) {
            return getKthElement(nums1, nums2, (n+1)/2);
        } else {
            return (getKthElement(nums1, nums2, n/2) + getKthElement(nums1, nums2, n/2 + 1)) / 2.0;
        }
    }
private:
    int getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int ind1 = 0;
        int ind2 = 0;
        while (true) {
            if (ind1 >= m) {
                return nums2[ind2 + k - 1];
            }
            if (ind2 >= n) {
                return nums1[ind1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[ind1], nums2[ind2]);
            }

            int newInd1 = min(ind1 + k/2 - 1, m - 1);
            int newInd2 = min(ind2 + k/2 - 1, n - 1);
            if (nums1[newInd1] <= nums2[newInd2]) {
                k -= newInd1 - ind1 + 1;
                ind1 = newInd1 + 1;
            } else {
                k -= newInd2 - ind2 + 1;
                ind2 = newInd2 + 1;
            }
        }
    }
};

int main() {
    {
        Solution sol;
        vector<int> nums1 = {1, 3};
        vector<int> nums2 = {2};
        // 2
        cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    }
    {
        Solution sol;
        vector<int> nums1 = {1, 2};
        vector<int> nums2 = {3, 4};
        // 2.5
        cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    }
    return 0;
}