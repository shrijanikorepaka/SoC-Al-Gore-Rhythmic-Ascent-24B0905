def min_operations_to_make_matrix_nice(t, test_cases):
    results = []
    for case in test_cases:
        n, m, matrix = case
        cost = 0
        for i in range((n + 1) // 2):
            for j in range((m + 1) // 2):
                # Collect all symmetric positions
                positions = [
                    matrix[i][j],
                    matrix[i][m - j - 1],
                    matrix[n - i - 1][j],
                    matrix[n - i - 1][m - j - 1]
                ]
                # Use set to avoid repeating same positions (for center rows/cols)
                unique_positions = list(set((i, j) for i, j in [
                    (i, j), (i, m - j - 1), (n - i - 1, j), (n - i - 1, m - j - 1)
                ]))
                values = [matrix[x][y] for x, y in unique_positions]
                values.sort()
                median = values[len(values) // 2]
                cost += sum(abs(v - median) for v in values)
        results.append(cost)
    return results

# Read input
t = int(input())
test_cases = []
for _ in range(t):
    n, m = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(n)]
    test_cases.append((n, m, matrix))

# Get results
results = min_operations_to_make_matrix_nice(t, test_cases)

# Output
for res in results:
    print(res)
