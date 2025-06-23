import heapq
import sys
input = sys.stdin.read

data = input().split()
n = int(data[0])
customers = []
index = 1
for i in range(n):
    a = int(data[index])
    b = int(data[index + 1])
    customers.append((a, b, i))
    index += 2

# Sort by arrival time
customers.sort()

# Min-heap of (departure time, room number)
heap = []
result = [0] * n
room_count = 0

# Assign rooms
for a, b, idx in customers:
    if heap and heap[0][0] < a:
        # Reuse room
        end_time, room_no = heapq.heappop(heap)
    else:
        # Allocate new room
        room_count += 1
        room_no = room_count
    result[idx] = room_no
    heapq.heappush(heap, (b, room_no))

# Output
print(room_count)
print(' '.join(map(str, result)))
