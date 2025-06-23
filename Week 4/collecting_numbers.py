# Read input
n = int(input())                      # Size of the array
arr = list(map(int, input().split()))  # The array of n integers

# pos[i] will store the position (index) of number i in the original array
pos = [0] * (n + 1)

# Fill in the position array
for index in range(n):
    value = arr[index]
    pos[value] = index

# Initialize rounds counter
rounds = 1  # We always need at least one round to start

# Go through numbers from 2 to n
for i in range(2, n + 1):
    # If the position of i is before the position of i-1,
    # it means we cannot collect i in the same pass as i-1
    if pos[i] < pos[i - 1]:
        rounds += 1  # So we need a new round

# Output the total number of rounds
print(rounds)
