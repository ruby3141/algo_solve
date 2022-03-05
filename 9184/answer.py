from sys import stdin

# I tried [[[None]*21]*21]*21, but it doesn't work because it shallow copies the list.
wbuffer = [[[None] * 21 for _ in range(21)] for _ in range(21)]
def w(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    elif a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)
    elif wbuffer[a][b][c] is not None:
        return wbuffer[a][b][c]
    elif a < b < c:
        wbuffer[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
        return wbuffer[a][b][c]
    else:
        wbuffer[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)
        return wbuffer[a][b][c]

while(True):
    a, b, c = [int(x) for x in stdin.readline().split()]
    if a == -1 and b == -1 and c == -1:
        exit()
    print(f"w({a}, {b}, {c}) = {w(a, b, c)}")