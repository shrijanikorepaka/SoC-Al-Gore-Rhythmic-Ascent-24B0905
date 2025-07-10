import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

visited = [0] * (n + 1)  # 0 = unvisited, 1 = visiting, 2 = visited
parent = [-1] * (n + 1)
cycle_start = -1
cycle_end = -1

def dfs(u):
    global cycle_start, cycle_end
    visited[u] = 1
    for v in graph[u]:
        if visited[v] == 0:
            parent[v] = u
            if dfs(v):
                return True
        elif visited[v] == 1:
            # Found cycle
            cycle_start = v
            cycle_end = u
            return True
    visited[u] = 2
    return False

for i in range(1, n + 1):
    if visited[i] == 0:
        if dfs(i):
            break

if cycle_start == -1:
    print("IMPOSSIBLE")
else:
    cycle = []
    cycle.append(cycle_start)
    v = cycle_end
    while v != cycle_start:
        cycle.append(v)
        v = parent[v]
    cycle.append(cycle_start)
    cycle.reverse()

    print(len(cycle))
    print(*cycle)
