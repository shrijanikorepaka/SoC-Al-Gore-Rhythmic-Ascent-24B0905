n = int(input())
x = list(map(int, input().split()))

# dp[i][j] = best difference current player can achieve in x[i..j]
dp = [ [0]*n for _ in range(n) ]

for i in range(n):
    dp[i][i] = x[i]

for length in range(2, n+1):
    for l in range(n - length + 1):
        r = l + length - 1
        dp[l][r] = max(
            x[l] - dp[l+1][r],
            x[r] - dp[l][r-1]
        )

total_sum = sum(x)
first_player_score = (total_sum + dp[0][n-1]) // 2
print(first_player_score)
