n = input().strip()
m = input().strip()

len_n = len(n)
len_m = len(m)

# Create DP table
dp = [[0] * (len_m + 1) for _ in range(len_n + 1)]

# Initialize base cases
for i in range(len_n + 1):
    dp[i][0] = i
for j in range(len_m + 1):
    dp[0][j] = j

# Fill DP table
for i in range(1, len_n + 1):
    for j in range(1, len_m + 1):
        if n[i-1] == m[j-1]:
            dp[i][j] = dp[i-1][j-1]
        else:
            dp[i][j] = 1 + min(
                dp[i-1][j],     # delete
                dp[i][j-1],     # insert
                dp[i-1][j-1]    # replace
            )

print(dp[len_n][len_m])
