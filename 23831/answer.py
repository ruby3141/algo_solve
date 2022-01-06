from sys import stdin
dbgprint = lambda _: None
N = int(stdin.readline())
A, B = [int(x) for x in stdin.readline().split()]
PQ, R, S = [], [], []
for _ in range(N):
    p, q, r, s = [int(x) for x in stdin.readline().split()]
    PQ.append(max(p, q))
    R.append(r)
    S.append(s)

result:int = 0
def loop(i:int, a:int, b:int, wasR:bool, lastvalue:int):
    dbgprint(f"i:{i}, a:{a}, b:{b}, wasR:{wasR}, lastvalue:{lastvalue}")
    global result
    if i == N:
        if result < lastvalue:
            result = lastvalue
            dbgprint(f"end in {lastvalue}")
        return

    if N - i == B - b:
        remainderPQ = sum(PQ[i:])
        if result < lastvalue + remainderPQ:
            result = lastvalue + remainderPQ
            dbgprint(f"end in {lastvalue + remainderPQ}")
        return

    if a < A:
        loop(i + 1, a + 1, b, False, lastvalue + S[i])

    if wasR == False:
        loop(i + 1, a, b, True, lastvalue + R[i])

    loop(i + 1, a, b + 1, False, lastvalue + PQ[i])

loop(0, 0, 0, False, 0)
print(result)

