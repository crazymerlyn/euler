#include <iostream>
#include <ostream>
bool isvalid(long long i, long long sq) {
  if (i == sq) return true;
  if (i > sq) return false;

  for (long long mod = 10; mod < sq; mod *= 10) {
    long long val = sq % mod;
    if (isvalid(i - val, sq / mod)) return true;
  }
  return false;
}

int main() {
  int limit = 1e6;
  long long res = 0;
  for (long long i = 2; i <= limit; i++) {
    res += i * i * isvalid(i, i * i);
  }

  std::cout << res << std::endl;
  return 0;
}
