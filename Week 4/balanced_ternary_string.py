def balanced_ternary_string(n, s):
    s = list(s)
    target = n // 3
    count = [0, 0, 0]
    
    # Count frequency of '0', '1', '2'
    for ch in s:
        count[int(ch)] += 1
    
    # Left to right pass: try to fix excess of '1' and '2' with smaller needed '0'
    for i in range(n):
        curr = int(s[i])
        for c in range(3):
            if count[curr] > target and count[c] < target and c < curr:
                count[curr] -= 1
                count[c] += 1
                s[i] = str(c)
                break
    
    # Right to left pass: fix excess of '0' and '1' with bigger needed '2'
    for i in range(n-1, -1, -1):
        curr = int(s[i])
        for c in range(2, -1, -1):
            if count[curr] > target and count[c] < target and c > curr:
                count[curr] -= 1
                count[c] += 1
                s[i] = str(c)
                break

    return ''.join(s)


# Example usage:

n = int(input())
s = input().strip()

print(balanced_ternary_string(n, s))
