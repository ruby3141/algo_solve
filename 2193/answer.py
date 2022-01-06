from sys import stdin

N = int(stdin.readline())
a, b = 0, 1
for _ in range(N):
    a, b = b, a+b
print(a)