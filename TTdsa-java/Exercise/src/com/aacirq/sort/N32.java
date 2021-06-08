package com.aacirq.sort;

public class N32 {
    public static void main(String[] args) {
        N32 sol = new N32();
        int[] nums = {3, 32, 321};
        System.out.println(sol.PrintMinNumber(nums));

        int[] nums2 = {3, 5, 1, 4, 2};
        System.out.println(sol.PrintMinNumber(nums2));
    }

    public int partition(String[] strArray, int left, int right) {
        String pivot = strArray[left];
        while (left < right) {
            while (left < right && (pivot + strArray[right]).compareTo(strArray[right] + pivot) <= 0)
                --right;
            strArray[left] = strArray[right];
            while (left < right && (pivot + strArray[left]).compareTo(strArray[left] + pivot) > 0)
                ++left;
            strArray[right] = strArray[left];
        }
        strArray[left] = pivot;
        return left;
    }

    public void qsort(String[] strArray, int left, int right) {
        if (left < right) {
            int ind = partition(strArray, left, right);
            qsort(strArray, left, ind - 1);
            qsort(strArray, ind + 1, right);
        }
    }

    public String PrintMinNumber(int[] numbers) {
        if (numbers.length == 0)
            return "";

        String[] strArray = new String[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            strArray[i] = String.valueOf(numbers[i]);
        }
        qsort(strArray, 0, numbers.length - 1);

        String res = "";
        for (String str : strArray) {
            res += str;
        }
        return res;
    }
}
