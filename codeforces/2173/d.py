def solve():
    n, k = (int(x) for x in input().split())
    a = [int(x) for x in input().split()]
    a.sort()
    hash = set()
    b = []
    for num in a:
        if num in hash:
            continue
        val = k // num
        b.append(num)
        for j in range(1, val + 1):
            hash.add(j * num)
            if len(hash) > n:
                print(-1)
                return
    print(len(b))
    for num in b:
        print(num, end=" ")
    print()


def main():
    t = int(input())

    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
