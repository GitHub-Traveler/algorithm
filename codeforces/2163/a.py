def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    flag = True
    for i in range(len(a) - 1):
        if i % 2 == 1:
            if a[i] != a[i + 1]:
                flag = False
                break

    if flag:
        print("YES")
    else:
        print("NO")


def main():
    t = int(input())

    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
