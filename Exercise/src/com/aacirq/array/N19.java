package com.aacirq.array;

import java.util.ArrayList;

public class N19 {
    public static void main(String[] args) {
        N19 sol = new N19();
        int[][] matrix1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        // 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10
        System.out.println(sol.printMatrix(matrix1));

        int[][] matrix2 = {{1, 2, 3, 4}};
        // 1,2,3,4
        System.out.println(sol.printMatrix(matrix2));

        int[][] matrix3 = {{1, 2, 3, 4}, {5, 6, 7, 8}};
        // 1,2,3,4,8,7,6,5
        System.out.println(sol.printMatrix(matrix3));

        int[][] matrix4 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        // 1,2,3,4,8,12,11,10,9,5,6,7
        System.out.println(sol.printMatrix(matrix4));

        int[][] matrix5 = {{1}, {2}, {3}, {4}};
        // 1, 2, 3, 4
        System.out.println(sol.printMatrix(matrix5));
    }

    public ArrayList<Integer> printMatrix(int[][] matrix) {
        ArrayList<Integer> res = new ArrayList<>();
        if (matrix.length == 0)
            return res;
        int left = 0, top = 0, right = matrix[0].length, bottom = matrix.length;
        while (left < right && top < bottom) {
            int i;
            for (i = left; i < right; i++) {
                res.add(matrix[top][i]);
            }
            for (i = top + 1; i < bottom; i++) {
                res.add(matrix[i][right - 1]);
            }
            if (top + 1 < bottom) {
                for (i = right - 2; i >= left; i--) {
                    res.add(matrix[bottom - 1][i]);
                }
            }
            if (left + 1 < right) {
                for (i = bottom - 2; i > top; i--) {
                    res.add(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
}
