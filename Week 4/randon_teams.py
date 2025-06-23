n, m = map(int, input().split())

# Maximum number of pairs
max_team_size = n - m + 1
kmax = max_team_size * (max_team_size - 1) // 2

# Minimum number of pairs
x = n // m
r = n % m
kmin = (m - r) * (x * (x - 1) // 2) + r * (x * (x + 1) // 2)

print(kmin, kmax)
