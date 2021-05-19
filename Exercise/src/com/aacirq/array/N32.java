package com.aacirq.array;

import java.util.ArrayList;
import java.util.Arrays;

public class N32 {
    private ArrayList<String> allComb;
    private String res;

    public static void main(String[] args) {
        N32 sol = new N32();
        int[] nums = {3, 32, 321};
        System.out.println(sol.PrintMinNumber(nums));
    }

    public String intArrayToString(int[] numbers) {
        StringBuffer b = new StringBuffer();
        for (int i : numbers) {
            b.append(i);
        }
        return b.toString();
    }

    public void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public void perm(int[] numbers, int ind) {
        if (ind + 1 == numbers.length) {
            String tmpStr = intArrayToString(numbers);
            if (tmpStr.compareTo(res) < 0) {
                res = tmpStr;
            }
        } else {
            for (int i = ind; i < numbers.length; i++) {
                swap(numbers, ind, i);
                perm(numbers, ind + 1);
                swap(numbers, ind, i);
            }
        }

    }

    public String PrintMinNumber(int[] numbers) {
        if (numbers.length == 0)
            return "";
        res = intArrayToString(numbers);
        perm(numbers, 0);
        return res;
    }
}
