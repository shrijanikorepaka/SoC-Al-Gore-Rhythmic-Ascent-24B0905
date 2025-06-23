MOD = 10**9 + 7

# Precompute Euler's Totient function up to max_n using a sieve
def compute_totients(max_n):
    phi = list(range(max_n + 1))
    for i in range(2, max_n + 1):
        if phi[i] == i:  # i is a prime
            for j in range(i, max_n + 1, i):
                phi[j] -= phi[j] // i
    return phi

# Fast modular exponentiation: (base^exp) % mod
def mod_pow(base, exp, mod):
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            result = result * base % mod
        base = base * base % mod
        exp //= 2
    return result

def count_necklaces(n, m):
    phi = compute_totients(n)
    result = 0

    # Iterate over all divisors of n
    for d in range(1, n + 1):
        if n % d == 0:
            term = phi[d] * mod_pow(m, n // d, MOD)
            result = (result + term) % MOD

    # Divide by n using modular inverse
    result = result * pow(n, MOD - 2, MOD) % MOD
    return result

# Input reading
n, m = map(int, input().split())
print(count_necklaces(n, m))
