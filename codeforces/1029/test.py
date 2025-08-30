def solve_cool_partition(arr):
    n = len(arr)
    if n == 0:
        return 0

    # Use dynamic programming with memoization
    memo = {}

    def dp(start_idx, required_set):
        # Convert set to tuple for hashing
        required_tuple = tuple(sorted(required_set))
        if (start_idx, required_tuple) in memo:
            return memo[(start_idx, required_tuple)]

        if start_idx == n:
            return 0

        max_segments = 0
        current_elements = set()

        # Try all possible ending positions for current segment
        for end_idx in range(start_idx, n):
            current_elements.add(arr[end_idx])

            # Check if current segment contains all required elements from previous segment
            if not required_set.issubset(current_elements):
                continue

            # If this is the last position, we can end here
            if end_idx == n - 1:
                max_segments = max(max_segments, 1)
                continue

            # Check if we can form next segment (remaining elements must contain all current elements)
            remaining_elements = set(arr[end_idx + 1 :])
            if current_elements.issubset(remaining_elements):
                # This segment is valid, recurse for remaining array
                segments_after = dp(end_idx + 1, current_elements)
                max_segments = max(max_segments, 1 + segments_after)

        memo[(start_idx, required_tuple)] = max_segments
        return max_segments

    return dp(0, set())


# Read input and solve
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    result = solve_cool_partition(arr)
    print(result)

