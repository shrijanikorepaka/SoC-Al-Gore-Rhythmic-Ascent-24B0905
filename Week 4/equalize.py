from math import gcd

def solve(a, b, c, d):
    # monitor_area = a * b
    monitor_area = a * b

    # Try scaling by width:
    # width = a, height = a * d / c
    # if a * d <= b * c, it fits
    if a * d <= b * c:
        # movie_area = a * (a * d / c) = (a * a * d) / c
        num = a * a * d
        den = c
    else:
        # scale by height
        # height = b, width = b * c / d
        # movie_area = b * (b * c / d) = (b * b * c) / d
        num = b * b * c
        den = d

    # movie_area = num / den
    # empty_area = monitor_area - movie_area = (monitor_area * den - num) / den
    p = monitor_area * den - num
    q = monitor_area * den

    g = gcd(p, q)
    p //= g
    q //= g

    print(f"{p}/{q}")

# Read input
a, b, c, d = map(int, input().split())
solve(a, b, c, d)
