package com.aacirq.array;

public class N01 {
    public static void main(String[] args) {
        N01 solution = new N01();

        int[][] nums = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
        // true
        System.out.println(solution.Find(7, nums));
        // false
        System.out.println(solution.Find(3, nums));
    }

    public boolean Find(int target, int[][] array) {
        if (array.length == 0)
            return false;
        int r = 0;
        int c = array[0].length - 1;
        while (r < array.length && c >= 0) {
            if (target < array[r][c]) {
                --c;
            } else if (target > array[r][c]) {
                ++r;
            } else {
                return true;
            }
        }
        return false;
    }
}
