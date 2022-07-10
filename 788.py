from utils import modinv

mod = 10 ** 9 + 7

fac = [1] * 2023
for i in range(1, len(fac)):
    fac[i] = fac[i-1] * i % mod

ifac = [modinv(x, mod) for x in fac]

def comb(n,k):
    return fac[n] * ifac[n-k] * ifac[k] % mod

def g(k, n):
    return 9 * comb(n, k) * pow(9, n-k, mod) % mod

def f(n):
    return sum(g(k, n) for k in range(n//2+1, n+1))

print(sum(f(i) for i in range(1, 2023)) % mod)
