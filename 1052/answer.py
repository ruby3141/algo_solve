from sys import stdin
import math

N, K = [int(x) for x in stdin.readline().split()]

if bin(N).count("1") <= K:
    print("0")

while K > 1 and N > 0:
    N -= 2 ** int(math.log(N, 2))
    K -= 1

print(f"{2 ** int(math.log(N, 2) + 1) - N}")