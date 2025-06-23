n = int(input())
tasks = [tuple(map(int, input().split())) for _ in range(n)]

# Sort by duration (a)
tasks.sort()

current_time = 0
reward = 0

for duration, deadline in tasks:
    current_time += duration
    reward += deadline - current_time

print(reward)
