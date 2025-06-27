MOD = 10**9 + 7
MAX_N = 10**6

a = [0] * (MAX_N + 2)
b = [0] * (MAX_N + 2)

a[1] = 1
b[1] = 1

for n in range(2, MAX_N + 1):
    a[n] = (4 * a[n-1] + b[n-1]) % MOD
    b[n] = (a[n-1] + 2 * b[n-1]) % MOD

t = int(input())
for _ in range(t):
    n = int(input())
    res = (a[n] + b[n]) % MOD
    print(res)
