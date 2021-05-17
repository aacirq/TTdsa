package com.aacirq.array;

public class N13 {
    public static void main(String[] args) {
        N13 sol = new N13();

        int[] array1 = {1, 2, 3, 4};
        print_array(sol.reOrderArray(array1));

        int[] array2 = {};
        print_array(sol.reOrderArray(array2));
    }

    public static void print_array(int[] array) {
        System.out.print("[");
        for (int j : array) {
            System.out.printf("%d ", j);
        }
        System.out.print("]\n");
    }

    public int[] reOrderArray(int[] array) {
        int[] res = new int[array.length];
        int res_ind = 0;

        for (int j : array) {
            if (j % 2 == 1) {
                res[res_ind] = j;
                res_ind++;
            }
        }

        for (int j : array) {
            if (j % 2 == 0) {
                res[res_ind] = j;
                res_ind++;
            }
        }
        return res;
    }
}
