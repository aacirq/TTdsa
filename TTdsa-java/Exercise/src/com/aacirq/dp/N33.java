package com.aacirq.dp;

public class N33 {
    public static void main(String[] args) {
        N33 sol = new N33();

        for (int i = 0; i < 10; i++) {
            System.out.println(sol.GetUglyNumber_Solution(i));
        }
    }

    public int GetUglyNumber_Solution(int index) {
        if (index == 0) return 0;
        int[] arr = new int[index];
        arr[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < index; i++) {
            int n2 = 2 * arr[p2], n3 = 3 * arr[p3], n5 = 5 * arr[p5];
            arr[i] = Math.min(n2, Math.min(n3, n5));
            if (arr[i] == n2) p2++;
            if (arr[i] == n3) p3++;
            if (arr[i] == n5) p5++;
        }
        return arr[index - 1];
    }
}
