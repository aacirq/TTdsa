//
// Created by renxin on 2021/6/8.
//

#include "ttdsa.h"

class Search {
public:
    static int binary_search_standard(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] == target)
            return left;
        else
            return -1;
    }

    static int binary_search_min_larger_equal(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] >= target)
            return left;
        else
            return -1;
    }

    static int binary_search_min_larger(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] > target)
            return left;
        else if(arr[left] == target && left + 1 < arr.size())
            return left + 1;
        else
            return -1;
    }

    static int binary_search_max_less_equal(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] == target)
            return left;
        else if(arr[left] > target)
            if(left > 0) return left - 1;
            else         return -1;
        else
            return left;
    }

    static int binary_search_max_less(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] >= target)
            if(left > 0) return left - 1;
            else         return -1;
        else
            return left;
    }
};

static void test_binary_search(const vector<int> vec, const vector<int> target_vec, int (*search_fun)(const vector<int> &, int)) {
    vector<int> ret(target_vec.size());

    for (int i = 0; i < target_vec.size(); ++i)
        ret[i] = search_fun(vec, target_vec[i]);
    cout << "vec: ";
    for (auto i : vec)
        printf("%4d", i);
    cout << endl << "tar: ";
    for (auto i : target_vec)
        printf("%4d", i);
    cout << endl << "ret: ";
    for (auto i : ret)
        printf("%4d", i);
    cout << endl;
}

int main() {
    vector<int> vec = { 1, 3, 5, 7, 9 };
    vector<int> target_vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "binary search (standard)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_standard);

    cout << endl;
    cout << "binary search (minimum of all elements <larger equal> than target)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_min_larger_equal);

    cout << endl;
    cout << "binary search (minimum of all elements <larger> than target)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_min_larger);

    cout << endl;
    cout << "binary search (maximum of all elements <less equal> than target)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_max_less_equal);

    cout << endl;
    cout << "binary search (maximum of all elements <less> than target)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_max_less);

    return 0;
}
