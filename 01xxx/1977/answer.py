import math

M = int(input())
N = int(input())
sm = math.ceil(math.sqrt(M))
sn = math.floor(math.sqrt(N))

if sm > sn:
    print(-1)

else:
    print(sum([x ** 2 for x in range(sm, sn + 1)]))
    print(sm ** 2)