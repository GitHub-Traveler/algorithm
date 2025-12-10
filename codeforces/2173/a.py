def solve():
    n, k = (int(x) for x in input().split())
    s = input()
    lte = -1
    result = 0
    for i in range(n):
        if s[i] == "1":
            lte = i + k
        if s[i] == "0" and i > lte:
            result += 1
    print(result)
    return


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
