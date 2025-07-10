import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

visited = [False] * (n+1)

def dfs(node):
    stack = [node]
    comp_nodes = []
    while stack:
        u = stack.pop()
        if not visited[u]:
            visited[u] = True
            comp_nodes.append(u)
            for v in adj[u]:
                if not visited[v]:
                    stack.append(v)
    return comp_nodes

components = []
for city in range(1, n+1):
    if not visited[city]:
        comp_nodes = dfs(city)
        components.append(comp_nodes)

# Number of roads to add is number_of_components - 1
k = len(components) - 1
print(k)
for i in range(k):
    # Connect one city from component i to one city from component i+1
    print(components[i][0], components[i+1][0])
