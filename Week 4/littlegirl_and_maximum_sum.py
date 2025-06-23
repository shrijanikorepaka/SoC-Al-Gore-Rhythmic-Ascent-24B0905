n, q = map(int, input().split())
a = list(map(int, input().split()))

# Frequency array to keep track of how often each index is included in queries
freq = [0] * (n + 2)

# Read each query and use prefix sum trick
for _ in range(q):
    l, r = map(int, input().split())
    freq[l] += 1
    freq[r + 1] -= 1

# Compute prefix sum to get actual frequencies
for i in range(1, n + 1):
    freq[i] += freq[i - 1]

# Only need first n frequencies (ignore index 0 and n+1)
freq = freq[1:n + 1]

# Sort frequencies and array
freq.sort()
a.sort()

# Maximize sum
result = sum(f * val for f, val in zip(freq, a))
print(result)
