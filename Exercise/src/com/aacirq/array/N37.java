package com.aacirq.array;

public class N37 {
    public static void main(String[] args) {
        N37 sol = new N37();

        int[] nums1 = {1,2,3,3,3,3,4,5};
        // 4
        System.out.println(sol.GetNumberOfK(nums1, 3));
        // 0
        System.out.println(sol.GetNumberOfK(nums1, 0));
        // 1
        System.out.println(sol.GetNumberOfK(nums1, 1));
        // 1
        System.out.println(sol.GetNumberOfK(nums1, 2));
        // 1
        System.out.println(sol.GetNumberOfK(nums1, 4));
        // 1
        System.out.println(sol.GetNumberOfK(nums1, 5));
        // 0
        System.out.println(sol.GetNumberOfK(nums1, 6));
    }

    public int GetNumberOfK(int[] array, int k) {
        int left = 0, right = array.length - 1;
        int mid;
        int res = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (array[mid] < k) {
                left = mid + 1;
            } else if (array[mid] > k) {
                right = mid - 1;
            } else {
                int tl = mid - 1;
                while (tl >= left && array[tl] == k)
                    --tl;
                int tr = mid + 1;
                while (tr <= right && array[tr] == k)
                    ++tr;
                res = tr - tl - 1;
                break;
            }
        }
        return res;
    }
}
