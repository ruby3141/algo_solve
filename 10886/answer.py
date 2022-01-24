from sys import stdin

N = int(stdin.readline())
inputsum = sum([int(stdin.readline()) for _ in range(N)])
if N / 2 > N - inputsum:
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")