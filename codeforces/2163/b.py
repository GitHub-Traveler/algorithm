import copy


def check(
    p: list[int],
    x: list[int],
    s: list[int],
    n: int,
    current_ops: list,
    current_step: int,
) -> list | None:
    if current_step == 5:
        flag = True
        for i in range(n):
            if x[i] == 1 and s[i] == 0:
                flag = False
                break
        if flag:
            return current_ops
        else:
            return None
    else:
        current_max = 0
        current_max_index = -1
        max_left = -1
        max_right = -1
        min_left = -1
        min_right = -1
        for i in range(n):
            if s[i] == 0 and x[i] == 1 and p[i] > current_max:
                current_max = p[i]
                current_max_index = i

        if current_max_index == -1:
            return current_ops
        else:
            for i in range(0, current_max_index):
                if p[i] < current_max and min_left == -1:
                    min_left = i
                if p[i] > current_max and max_left == -1:
                    max_left = i

            for i in range(n - 1, current_max_index, -1):
                if p[i] < current_max and min_right == -1:
                    min_right = i
                if p[i] > current_max and max_right == -1:
                    max_right = i
            final_ops = None
            if max_right != -1 and min_left != -1:
                new_s = copy.deepcopy(s)
                new_ops = current_ops + [[min_left + 1, max_right + 1]]
                for i in range(min_left + 1, max_right):
                    if x[i] == 1:
                        new_s[i] = 1
                final_ops = check(p, x, new_s, n, new_ops, current_step + 1)

            if final_ops is not None:
                return final_ops

            if max_left != -1 and min_right != -1:
                new_s = copy.deepcopy(s)
                new_ops = current_ops + [[max_left + 1, min_right + 1]]
                for i in range(max_left + 1, min_right):
                    if x[i] == 1:
                        new_s[i] = 1
                final_ops = check(p, x, new_s, n, new_ops, current_step + 1)

            return final_ops


def solve():
    n = int(input())
    p = list(map(int, input().split()))
    x = [int(c) for c in input()]
    s = [0] * n
    result = check(p, x, s, n, [], 0)
    if result is None:
        print(-1)
    else:
        print(len(result))
        [print(x[0], x[1]) for x in result]


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
