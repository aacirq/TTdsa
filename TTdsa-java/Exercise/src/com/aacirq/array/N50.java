package com.aacirq.array;

import java.util.HashSet;

public class N50 {
    public static void main(String[] args) {
        N50 sol = new N50();

        int[] array = {2, 3, 1, 0, 2, 5, 3};
        // 2或者3
        System.out.println(sol.duplicate(array));
    }

    public int duplicate (int[] numbers) {
        int[] hash = new int[numbers.length];
        for (int number : numbers) {
            hash[number]++;
            if (hash[number] > 1)
                return number;
        }
        return -1;
    }
}
