def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    highest = 0
    lowest = 0
    for i in range(n):
        next_highest = max(highest - a[i], b[i] - lowest)
        next_lowest = min(lowest - a[i], b[i] - highest)
        highest, lowest = next_highest, next_lowest
    print(highest)
    return


def main():
    t = int(input())

    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
