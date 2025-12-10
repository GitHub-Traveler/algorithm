def solve():
    s = input()
    n = len(s)
    cnt = 1
    result = 1
    for i in range(n):
        if s[i] == "*":
            if i != n - 1:
                if s[i + 1] == "<" or s[i + 1] == "*":
                    print(-1)
                    return
            if i != 0:
                if s[i - 1] == ">" or s[i - 1] == "*":
                    print(-1)
                    return
        if i != n - 1:
            if s[i] == ">" and s[i + 1] == "<":
                print(-1)
                return
        if i != 0:
            if s[i] == "*":
                result = max(result, cnt + 1)
            if s[i] == s[i - 1] or s[i - 1] == "*":
                cnt += 1
            else:
                cnt = 1
        result = max(result, cnt)
    print(result)


def main():
    t = int(input())

    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
