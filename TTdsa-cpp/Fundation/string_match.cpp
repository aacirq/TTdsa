#include <cmath>
#include <iostream>
#include <string>

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
}

int main() {
  test("aaab", "aaab");
  test("aaab", "aa");
  test("aaab", "a");
  test("000000100000101000", "000001");
  return 0;
}