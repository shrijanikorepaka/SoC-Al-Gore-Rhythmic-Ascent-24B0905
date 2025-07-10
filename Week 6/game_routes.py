MOD = 10**9 + 7
from collections import deque, defaultdict

n, m = map(int, input().split())

adj = [[] for _ in range(n + 1)]
in_deg = [0] * (n + 1)

for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    in_deg[b] += 1

# Topological sort using Kahn's algorithm
topo = []
q = deque()

for i in range(1, n + 1):
    if in_deg[i] == 0:
        q.append(i)

while q:
    u = q.popleft()
    topo.append(u)
    for v in adj[u]:
        in_deg[v] -= 1
        if in_deg[v] == 0:
            q.append(v)

# DP to count paths
dp = [0] * (n + 1)
dp[1] = 1

for u in topo:
    for v in adj[u]:
        dp[v] = (dp[v] + dp[u]) % MOD

print(dp[n])
