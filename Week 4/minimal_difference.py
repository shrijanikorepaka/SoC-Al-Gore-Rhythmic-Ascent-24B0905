def shortest_dominated_subarrays(test_cases):
    results = []

    for a in test_cases:
        last_index = {}
        min_len = float('inf')
        for i, val in enumerate(a):
            if val in last_index:
                # i - last_index[val] + 1 is the subarray length
                min_len = min(min_len, i - last_index[val] + 1)
            last_index[val] = i

        results.append(min_len if min_len != float('inf') else -1)

    return results

# Input reading
T = int(input())
test_cases = []
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    test_cases.append(a)

# Process
results = shortest_dominated_subarrays(test_cases)

# Output
for res in results:
    print(res)
