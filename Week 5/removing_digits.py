n = int(input())
dp = [0] + [float('inf')] * n

for x in range(1, n + 1):
    for digit_char in str(x):
        d = int(digit_char)
        if d > 0:
            dp[x] = min(dp[x], 1 + dp[x - d])

print(dp[n])
