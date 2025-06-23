t = int(input())
for _ in range(t):
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    cross = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1)
    if cross > 0:
        print("LEFT")
    elif cross < 0:
        print("RIGHT")
    else:
        print("TOUCH")
