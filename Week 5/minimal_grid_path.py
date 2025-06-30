n = int(input())
grid = [input().strip() for _ in range(n)]

# Frontier positions: set of tuples (i, j)
frontier = set()
frontier.add((0, 0))
result = grid[0][0]

for step in range(1, 2 * n - 1):
    next_positions = set()
    min_char = 'Z'
    # Collect all next positions and find minimal character
    for i, j in frontier:
        for ni, nj in [(i+1, j), (i, j+1)]:
            if ni < n and nj < n:
                c = grid[ni][nj]
                if c < min_char:
                    min_char = c
                    next_positions = {(ni, nj)}
                elif c == min_char:
                    next_positions.add((ni, nj))
    result += min_char
    frontier = next_positions

print(result)
