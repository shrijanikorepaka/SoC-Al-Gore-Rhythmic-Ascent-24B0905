MOD = 10**9 + 7

n = int(input())
grid = [input().strip() for _ in range(n)]

dp = [[0] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if grid[i][j] == '*':
            dp[i][j] = 0
        else:
            if i == 0 and j == 0:
                dp[i][j] = 1
            else:
                ways = 0
                if i > 0:
                    ways += dp[i-1][j]
                if j > 0:
                    ways += dp[i][j-1]
                dp[i][j] = ways % MOD

print(dp[n-1][n-1])
