#include "ttdsa.h"

class Search {
 public:
  /**
   * Binary search (standard)
   * @return index of element which is equal to target,
   *         or -1 if no elements are equal to target.
   */
  static int binary_search_standard(const vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ans;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] < target) {
        left = mid + 1;
      } else if (arr[mid] > target) {
        right = mid - 1;
      } else {
        return mid;
      }
    }
    return -1;
  }

  /**
   * Binary search minimum element whose value is larger than or equal to target
   * @return index of minimum element which is larger than or equal to target,
   *         or -1 if all elements are less than target.
   */
  static int binary_search_min_larger_equal(const vector<int> &arr,
                                            int target) {
    int left = 0, right = arr.size() - 1;
    int ans = arr.size();
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] >= target) {
        right = mid - 1;
        ans = mid;
      } else {
        left = mid + 1;
      }
    }
    if (ans == arr.size()) {
      return -1;
    }
    return ans;
  }

  /**
   * Binary search minimum element whose value is larger than target
   * @return index of mininum element which is larger than target,
   *         or -1 if all elements are less than target.
   */
  static int binary_search_min_larger(const vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ans = arr.size();
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] > target) {
        right = mid - 1;
        ans = mid;
      } else {
        left = mid + 1;
      }
    }
    if (ans == arr.size()) {
      return -1;
    }
    return ans;
  }

  /**
   * Binary search maximum element whose value is less than or equal to target
   * @return index of maximum element whose value is less than or equal to
   *         target, or -1 if all elements are larger than target
   */
  static int binary_search_max_less_equal(const vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ans = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] <= target) {
        left = mid + 1;
        ans = mid;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }

  /**
   * Binary search maximum element whose value is less than target
   * @return index of maximum element whose value is less than target,
   *         or -1 if all elements are NOT less than target.
   */
  static int binary_search_max_less(const vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ans = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] < target) {
        left = mid + 1;
        ans = mid;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
};

static void test_binary_search(const vector<int> vec,
                               const vector<int> target_vec,
                               const vector<int> answer,
                               int (*search_fun)(const vector<int> &, int)) {
  vector<int> ret(target_vec.size());

  for (int i = 0; i < target_vec.size(); ++i)
    ret[i] = search_fun(vec, target_vec[i]);
  cout << "vec:    ";
  for (auto i : vec) printf("%4d", i);
  cout << endl << "target: ";
  for (auto i : target_vec) printf("%4d", i);
  cout << endl << "return: ";
  for (auto i : ret) printf("%4d", i);
  cout << endl << "answer: ";
  for (auto i : answer) printf("%4d", i);
  cout << endl;
}

int main() {
  vector<int> vec = {1, 3, 5, 7, 9};
  vector<int> target_vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  {
    vector<int> answer = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4, -1};
    cout << "binary search (standard)" << endl;
    test_binary_search(vec, target_vec, answer, Search::binary_search_standard);
  }

  {
    cout << endl;
    vector<int> answer = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, -1};
    cout << "binary search (minimum of all elements <larger equal> than target)"
         << endl;
    test_binary_search(vec, target_vec, answer,
                       Search::binary_search_min_larger_equal);
  }

  {
    cout << endl;
    vector<int> answer = {0, 1, 1, 2, 2, 3, 3, 4, 4, -1, -1};
    cout << "binary search (minimum of all elements <larger> than target)"
         << endl;
    test_binary_search(vec, target_vec, answer,
                       Search::binary_search_min_larger);
  }

  {
    cout << endl;
    vector<int> answer = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4};
    cout << "binary search (maximum of all elements <less equal> than target)"
         << endl;
    test_binary_search(vec, target_vec, answer,
                       Search::binary_search_max_less_equal);
  }

  {
    cout << endl;
    vector<int> answer = {-1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 4};
    cout << "binary search (maximum of all elements <less> than target)"
         << endl;
    test_binary_search(vec, target_vec, answer, Search::binary_search_max_less);
  }

  return 0;
}
