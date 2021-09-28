#include <cmath>
#include <iostream>
#include <string>
#include <vector>

bool same(const std::string &str, const std::string &pattern, int str_ind) {
  int m = pattern.size();
  for (int i = 0; i < m; ++i) {
    if (str[str_ind + i] != pattern[i]) {
      return false;
    }
  }
  return true;
}

void native_string_matcher(const std::string &str, const std::string &pattern) {
  int n = str.size();
  int m = pattern.size();
  int thres = n - m + 1;
  for (int i = 0; i < thres; ++i) {
    if (same(str, pattern, i)) {
      std::cout << "Pattern occurs with shift " << i << std::endl;
    }
  }
}

static int pow_mod(int b, int exp, int q) {
  long long res = 1;
  long long base = b;
  while (exp > 0) {
    if (exp % 2 == 1) {
      res = (res * base) % q;
    }
    exp /= 2;
    base = (base * base) % q;
  }
  return static_cast<int>(res);
}

void rabin_karp_matcher(const std::string &str, const std::string &pattern,
                        int d, int q) {
  int n = str.size();
  int m = pattern.size();
  int p = 0;
  int t = 0;
  for (int i = 0; i < m; ++i) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + str[i]) % q;
  }

  int thres = n - m + 1;
  int h = pow_mod(d, m - 1, q);
  for (int i = 0; i < thres; ++i) {
    if (t == p) {
      if (same(str, pattern, i)) {
        std::cout << "Pattern occurs with shift " << i << std::endl;
      }
    }
    int c1 = str[i], c2 = str[m + i];
    t = ((d * (t - c1 * h % q) % q) % q + c2) % q;
    if (t < 0) {
      t += q;
    }
  }
}

static bool is_postfix(const std::string &pattern, int k, int q) {
  // check if pattern[0 ... k-1] (first k characters) is postfix of
  // pattern[0 ... q-1] (first q characters)
  int ind_start = q - k;
  for (int i = 0; i < k; ++i) {
    if (pattern[i] != pattern[ind_start + i]) return false;
  }
  return true;
}

void finite_automation_matcher(const std::string &str,
                               const std::string &pattern) {
  int m = pattern.size();
  int n_row = m + 1;
  int n_col = 128;
  std::vector<std::vector<int>> trans_func(n_row, std::vector<int>(n_col, 0));

  // Compute transition function
  for (int i_p = 0; i_p < n_row; ++i_p) {
    int t_k = std::min(m, i_p + 1);
    for (int c = 0; c < n_col; ++c) {
      int k = t_k;
      char t_c = static_cast<char>(c);
      while (k > 0 &&
             (!is_postfix(pattern, k - 1, i_p) || pattern[k - 1] != t_c)) {
        --k;
      }
      trans_func[i_p][c] = k;
    }
  }

  // Match
  int n = str.size();
  int q = 0;
  for (int i = 0; i < n; ++i) {
    q = trans_func[q][static_cast<int>(str[i])];
    if (q == m) {
      std::cout << "Pattern occurs with shift " << i - m + 1 << std::endl;
    }
  }
}

using std::cout;
using std::endl;
using std::string;

void test(const string &str, const string &pattern) {
  cout << endl;
  cout << "Match str{" << str << "} with pattern{" << pattern << "}" << endl;
  cout << "==> native_string_matcher" << endl;
  native_string_matcher(str, pattern);
  cout << "==> rabin_karp_matcher" << endl;
  rabin_karp_matcher(str, pattern, 256, 999983);
  cout << "==> finite_automation_matcher" << endl;
  finite_automation_matcher(str, pattern);
}

int main() {
  test("aaab", "aaab");
  test("aaab", "aa");
  test("aaab", "a");
  test("000000100000101000", "000001");
  return 0;
}