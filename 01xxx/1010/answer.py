from sys import stdin

T = int(stdin.readline())
for _ in range(T):
    N, M = (int(x) for x in stdin.readline().split())
    # M! / (N! * (M-N)!)
    ans = 1
    if N > M - N:
        for i in range(N + 1, M + 1):
            ans *= i
        for i in range(2, M - N + 1):
            ans //= i
    else:
        for i in range(M - N + 1, M + 1):
            ans *= i
        for i in range(2, N + 1):
            ans //= i
    print(ans)
