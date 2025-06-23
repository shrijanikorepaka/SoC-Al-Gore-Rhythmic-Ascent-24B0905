MOD = 10**9 + 7
MAX = 10**6 + 1

# Precompute factorials and inverse factorials
fact = [1] * MAX
inv_fact = [1] * MAX

# Compute all factorials % MOD
for i in range(1, MAX):
    fact[i] = fact[i - 1] * i % MOD

# Compute inverse of factorial[MAX-1] using Fermat’s Little Theorem
inv_fact[MAX - 1] = pow(fact[MAX - 1], MOD - 2, MOD)

# Compute all inverse factorials % MOD
for i in range(MAX - 2, -1, -1):
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD

# Process queries
n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    if b < 0 or b > a:
        print(0)
    else:
        result = fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD
        print(result)
