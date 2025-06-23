n = int(input())
a = list(map(int, input().split()))

# Arrays to hold positions of each tier size
pos1 = [0] * (n + 1)
pos2 = [0] * (n + 1)

# For each tier, find the two positions where it occurs
count = [0] * (n + 1)

for i in range(2 * n):
    tier = a[i]
    if count[tier] == 0:
        pos1[tier] = i + 1  # 1-based index of house
        count[tier] = 1
    else:
        pos2[tier] = i + 1
        count[tier] = 2

sasha_pos = 1
dima_pos = 1
total_distance = 0

for i in range(1, n + 1):
    # Option 1: Sasha -> pos1[i], Dima -> pos2[i]
    dist1 = abs(sasha_pos - pos1[i]) + abs(dima_pos - pos2[i])
    # Option 2: Sasha -> pos2[i], Dima -> pos1[i]
    dist2 = abs(sasha_pos - pos2[i]) + abs(dima_pos - pos1[i])

    if dist1 <= dist2:
        total_distance += dist1
        sasha_pos = pos1[i]
        dima_pos = pos2[i]
    else:
        total_distance += dist2
        sasha_pos = pos2[i]
        dima_pos = pos1[i]

print(total_distance)
