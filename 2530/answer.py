from sys import stdin

H, M, S = [int(x) for x in stdin.readline().split()]
T = int(stdin.readline())

S += T
M += S // 60
S %= 60
H += M // 60
M %= 60
H %= 24

print(f"{H} {M} {S}")