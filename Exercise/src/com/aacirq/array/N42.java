package com.aacirq.array;

import java.util.ArrayList;

public class N42 {
    public static void main(String[] args) {
        N42 sol = new N42();

        int[] array1 = {1, 2, 4, 7, 11, 15};
        // [4, 11]
        System.out.println(sol.FindNumbersWithSum(array1, 15));
    }

    // 题目要求如果有多对数字的和等于S，输出两个数的乘积最小的。
    // 但是可以证明，如果满足要求的数字对中，出现在最外侧的乘积最小。
    // 所以无需保存判断乘积。
    public ArrayList<Integer> FindNumbersWithSum(int[] array, int sum) {
        int ind1 = 0, ind2 = array.length - 1;
        ArrayList<Integer> res = new ArrayList<>();
        while (ind1 < ind2) {
            int tmp = array[ind1] + array[ind2];
            if (tmp > sum) {
                --ind2;
            } else if (tmp < sum) {
                ++ind1;
            } else {
                res.add(array[ind1]);
                res.add(array[ind2]);
                break;
            }
        }
        return res;
    }
}
