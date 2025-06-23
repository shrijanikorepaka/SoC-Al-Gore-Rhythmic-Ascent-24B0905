q = int(input())
for _ in range(q):
    n = int(input())
    sticks = list(map(int, input().split()))
    sticks.sort()
    
    # Check pairs
    possible = True
    for i in range(0, 4 * n, 2):
        if sticks[i] != sticks[i+1]:
            possible = False
            break
    
    if not possible:
        print("NO")
        continue
    
    area = sticks[0] * sticks[-1]
    
    for i in range(n):
        if sticks[2*i] * sticks[4*n - 2*i - 1] != area:
            possible = False
            break
    
    print("YES" if possible else "NO")
