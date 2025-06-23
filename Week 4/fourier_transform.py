n = int(input())
a = [float(input()) for _ in range(n)]

floor_vals = [int(a_i // 1) if a_i >= 0 else int(a_i // 1) - (1 if a_i % 1 != 0 else 0) for a_i in a]
# Python floor equivalent:
# For positive numbers floor(a_i) is int(a_i)
# For negative numbers floor(a_i) is int(a_i) if a_i is integer else int(a_i)-1

# But since a_i has exactly 5 decimals, we can just use math.floor:
import math
floor_vals = [math.floor(x) for x in a]

S = sum(floor_vals)
D = -S  # number of ceil operations needed

b = floor_vals[:]  # start with all floors
# We will switch D of them to ceil

# Find indices where a_i is not integer (i.e. ceil != floor)
non_int_indices = [i for i in range(n) if not math.isclose(a[i], floor_vals[i])]

for i in non_int_indices[:D]:
    b[i] += 1  # change floor to ceil

for x in b:
    print(x)
