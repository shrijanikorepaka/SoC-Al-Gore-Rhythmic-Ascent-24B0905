MOD = 10**9 + 7  # Modulo value as required in the problem
MAX = 2 * 10**6 + 5  # Maximum size needed for factorials (n + m)

# Precompute factorials and their modular inverses
fact = [1] * MAX         # fact[i] will store i! % MOD
inv_fact = [1] * MAX     # inv_fact[i] will store (i!)^(-1) % MOD

# Compute all factorials up to MAX
for i in range(1, MAX):
    fact[i] = fact[i - 1] * i % MOD

# Compute inverse of the last factorial using Fermat's Little Theorem
# a^(MOD-2) % MOD is the modular inverse of a when MOD is prime
inv_fact[MAX - 1] = pow(fact[MAX - 1], MOD - 2, MOD)

# Compute inverse factorials in reverse order
for i in range(MAX - 2, -1, -1):
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD

# Function to compute binomial coefficient C(a, b) modulo MOD
def binom(a, b):
    if b < 0 or b > a:
        return 0  # Invalid case
    return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD

# Read input values: number of children n and apples m
n, m = map(int, input().split())

# Use stars and bars: C(n + m - 1, m) gives the number of ways
result = binom(n + m - 1, m)

# Print the final result
print(result)
