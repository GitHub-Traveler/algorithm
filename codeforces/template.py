def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    num_even = 0
    num_odd = 0
    first_even = -1
    second_even = -1
    for i in range(n):
        if a[i] % 2 == 0:
            num_even += 1
            if first_even == -1:
                first_even = i
            elif second_even == -1:
                second_even = i
        else:
            num_odd += 1
    flag = True
    if num_even >= 2:
        flag = False
        print(a[first_even], a[second_even])
    else:
        for i in range(n):
            for j in range(i + 1, n):
                if (a[j] % a[i]) % 2 == 0:
                    print(a[i], a[j])
                    flag = False
                    break
            if not flag:
                break
    if flag:
        print(-1)


def main():
    t = int(input())

    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
