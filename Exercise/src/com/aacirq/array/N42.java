package com.aacirq.array;

import java.util.ArrayList;

public class N42 {
    public static void main(String[] args) {
        N42 sol = new N42();

        int[] array1 = {1, 2, 4, 7, 11, 15};
        // [4, 11]
        System.out.println(sol.FindNumbersWithSum(array1, 15));
    }

    public ArrayList<Integer> FindNumbersWithSum(int[] array, int sum) {
        int num1 = 0, num2 = 0;
        int ind1 = 0, ind2 = array.length - 1;
        int product = Integer.MAX_VALUE;
        while (ind1 < ind2) {
            int tmp = array[ind1] + array[ind2];
            if (tmp > sum) {
                --ind2;
            } else if (tmp < sum) {
                ++ind1;
            } else {
                if (array[ind1] * array[ind2] < product) {
                    num1 = array[ind1];
                    num2 = array[ind2];
                    product = num1 * num2;
                }
                ++ind1;
                --ind2;
            }
        }
        ArrayList<Integer> res = new ArrayList<>();
        if (num1 != 0 || num2 != 0) {
            res.add(num1);
            res.add(num2);
        }
        return res;
    }
}
