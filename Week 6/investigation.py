import heapq
import sys

sys.setrecursionlimit(1 << 25)
input = sys.stdin.readline

MOD = 10**9 + 7
INF = float('inf')

def main():
    n, m = map(int, input().split())
    adj = [[] for _ in range(n + 1)]
    
    for _ in range(m):
        a, b, c = map(int, input().split())
        adj[a].append((b, c))
    
    dist = [INF] * (n + 1)
    ways = [0] * (n + 1)
    min_flights = [INF] * (n + 1)
    max_flights = [0] * (n + 1)

    dist[1] = 0
    ways[1] = 1
    min_flights[1] = 0

    pq = [(0, 1)]  # (distance, node)
    
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                ways[v] = ways[u]
                min_flights[v] = min_flights[u] + 1
                max_flights[v] = max_flights[u] + 1
                heapq.heappush(pq, (dist[v], v))
            elif dist[v] == dist[u] + w:
                ways[v] = (ways[v] + ways[u]) % MOD
                min_flights[v] = min(min_flights[v], min_flights[u] + 1)
                max_flights[v] = max(max_flights[v], max_flights[u] + 1)
    
    print(dist[n], ways[n], min_flights[n], max_flights[n])

if __name__ == "__main__":
    main()
