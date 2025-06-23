# Maximum value of x (as per constraints)
MAX = 10**6 + 1

# Precompute the number of divisors for all numbers from 1 to MAX
divisors = [0] * MAX

# Using a modified sieve to count divisors
for i in range(1, MAX):
    # Every multiple of i has i as a divisor
    for j in range(i, MAX, i):
        divisors[j] += 1

# Read input
n = int(input())  # Number of integers

# Process each query
for _ in range(n):
    x = int(input())
    print(divisors[x])
