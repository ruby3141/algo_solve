a = [int(input()) for _ in range(9)]
asum = sum(a)
a.sort()

for i in range(9):
    for j in range(i + 1, 9):
        if asum - a[i] - a[j] == 100:
            [print(a[k]) for k in range(9) if k not in (i,j)]
            exit()
