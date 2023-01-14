#include <iostream>
#include <ostream>
#include <set>
#include <vector>

long long reverse(long long x) {
  long long res = 0;
  while (x) {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  long long limit = 4e7;
  std::vector<bool> isprime(limit + 1, true);
  for (long long i = 2; i * i <= limit; ++i) {
    for (long long j = i * i; j <= limit; j += i) isprime[j] = false;
  }
  std::set<long long> primesqs;
  for (long long i = 2; i <= limit; ++i) {
    if (!isprime[i]) continue;
    primesqs.insert(i * i);
  }

  long long res = 0;
  int count = 0;
  for (auto primesq : primesqs) {
    if (reverse(primesq) != primesq &&
        primesqs.find(reverse(primesq)) != primesqs.end()) {
      res += primesq;
      count += 1;
      if (count == 50) break;
    }
  }
  std::cout << res << std::endl;
}
