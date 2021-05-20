package com.aacirq.sort;

public class N35 {
    public static void main(String[] args) {
        N35 sol = new N35();

        int nums1[] = {1, 2, 3, 4, 5, 6, 7, 0};
        // 7
        System.out.println(sol.InversePairs(nums1));

        int nums2[] = {6, 3, 8, 4, 2};
        // 7
        System.out.println(sol.InversePairs(nums2));

        int nums3[] = {0};
        // 0
        System.out.println(sol.InversePairs(nums3));

        int nums4[] = {1, 0};
        // 1
        System.out.println(sol.InversePairs(nums4));

        int nums5[] = {364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
        // 2519;
        System.out.println(sol.InversePairs(nums5));
    }

    int[] nums, tmp;

    public int InversePairs(int[] array) {
        nums = array;
        tmp = new int[array.length];
        return mergeSort(0, array.length - 1);
    }

    public int mergeSort(int low, int high) {
        if (low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        int res = mergeSort(low, mid) + mergeSort(mid + 1, high);
        for (int i = low; i <= high; i++) {
            tmp[i] = nums[i];
        }
        int ti = low, tj = mid + 1;
        for (int i = low; i <= high; i++) {
            if (ti > mid) {
                nums[i] = tmp[tj++];
            } else if (tj > high || tmp[ti] <= tmp[tj]) {
                nums[i] = tmp[ti++];
            } else {
                nums[i] = tmp[tj++];
                res += mid - ti + 1;
                res %= 1000000007;
            }
        }
        return res;
    }
}
