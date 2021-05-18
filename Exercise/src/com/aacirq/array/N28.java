package com.aacirq.array;

public class N28 {
    public static void main(String[] args) {
        N28 sol = new N28();

        int[] array1 = {1, 2, 3, 2, 2, 2, 5, 4, 2};
        // 2
        System.out.println(sol.MoreThanHalfNum_Solution(array1));

        int[] array2 = {3, 3, 3, 3, 2, 2, 2};
        // 3
        System.out.println(sol.MoreThanHalfNum_Solution(array2));

        int[] array3 = {1};
        // 1
        System.out.println(sol.MoreThanHalfNum_Solution(array3));
    }

    public int MoreThanHalfNum_Solution(int[] array) {
        int res = array[0];
        int count = 0;
        for (int i : array) {
            if (i == res)
                count++;
            else {
                count--;
                if (count == 0) {
                    res = i;
                    count = 1;
                }
            }
        }
        return res;
    }
}
