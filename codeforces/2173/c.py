import math


def solve():
    n, k = (int(x) for x in input().split())
    a = [int(x) for x in input().split()]
    a = list(dict.fromkeys(a))
    a.sort()
    mem = set()
    b = []
    for num in a:
        if num not in mem:
            b.append(num)
            for j in range(1, math.floor(k / num) + 1):
                mem.add(j * num)
    if len(mem) != n:
        print(-1)
    else:
        print(len(b))
        for num in b:
            print(num, end=" ")
        print()
    return


def main():
    t = int(input())

    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
