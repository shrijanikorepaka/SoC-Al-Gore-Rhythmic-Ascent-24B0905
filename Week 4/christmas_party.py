# Modulo value as per problem requirement
MOD = 10**9 + 7

def count_derangements(n):
    # Base cases:
    if n == 0:
        return 1  # One way to derange 0 elements (empty permutation)
    if n == 1:
        return 0  # No way to derange 1 element

    # Create a list to store derangement values from 0 to n
    dp = [0] * (n + 1)
    dp[0] = 1  # D(0) = 1
    dp[1] = 0  # D(1) = 0

    # Fill the dp array using the recurrence:
    # D(n) = (n - 1) * (D(n - 1) + D(n - 2))
    for i in range(2, n + 1):
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % MOD
        # Use modulo at every step to avoid large numbers

    return dp[n]

# Read input value
n = int(input())

# Output the number of derangements modulo 10^9+7
print(count_derangements(n))
