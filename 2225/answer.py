from sys import stdin

N, K = [int(x) for x in stdin.readline().split()]

if K == 1:
    print(1)
    exit()

currentEnd = [1] * (N + 1)
for _ in range(K - 2):
    nextEnd = [sum(currentEnd[x:]) for x in range(N + 1)]
    currentEnd = nextEnd

print(sum(currentEnd) % 1000000000)