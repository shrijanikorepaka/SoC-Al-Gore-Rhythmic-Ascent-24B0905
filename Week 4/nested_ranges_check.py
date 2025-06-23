import sys

def main():
    input = sys.stdin.read().split()
    ptr = 0
    n = int(input[ptr])
    ptr += 1
    ranges = []
    for i in range(n):
        x = int(input[ptr])
        y = int(input[ptr + 1])
        ptr += 2
        ranges.append((x, y, i))
    
    contains = [0] * n
    is_contained = [0] * n

    # Sort by x ascending, y descending to check is_contained
    sorted_ranges = sorted(ranges, key=lambda r: (r[0], -r[1]))
    max_y_so_far = -1
    for i in range(n):
        x, y, original_idx = sorted_ranges[i]
        if i > 0 and y <= max_y_so_far:
            is_contained[original_idx] = 1
        if y > max_y_so_far:
            max_y_so_far = y
    
    # Sort by x ascending, y ascending to check contains
    sorted_ranges = sorted(ranges, key=lambda r: (r[0], r[1]))
    # Process in reverse order
    min_y_so_far = float('inf')
    for i in range(n - 1, -1, -1):
        x, y, original_idx = sorted_ranges[i]
        if y >= min_y_so_far:
            contains[original_idx] = 1
        if y < min_y_so_far:
            min_y_so_far = y
    
    print(' '.join(map(str, contains)))
    print(' '.join(map(str, is_contained)))

if __name__ == '__main__':
    main()
