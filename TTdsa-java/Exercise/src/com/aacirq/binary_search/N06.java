package com.aacirq.binary_search;

public class N06 {
    public static void main(String[] args) {
        N06 sol = new N06();

        int[] array = {3, 4, 5, 1, 2};
        // 1
        System.out.println(sol.minNumberInRotateArray(array));
    }

    public int minNumberInRotateArray(int[] array) {
        if (array.length == 0)
            return 0;
        int left = 0, right = array.length - 1;
        while (left < right) {
            int m = left + (right - left) / 2;
            if (array[m] > array[right]) {
                left = m + 1;
            } else if (array[m] < array[right]) {
                right = m;
            } else {
                right--;
            }
        }
        return array[left];
    }
}
