input = input().split()
M = int(input[0])
N = int(input[1])

table = [True] * ((10 ** 6 // 2) + 1)
table[0] = False
for i in range(3, 1002, 2):
    if table[i // 2] == False:
        continue
    for j in range(i ** 2, len(table) * 2, i * 2):
        table[j // 2] = False

if M <= 2 and N > 1:
    print(2)
for i in range(M // 2, (N + 1) // 2):
    if table[i] == True:
        print(i * 2 + 1)
