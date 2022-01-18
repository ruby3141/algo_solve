from sys import stdin
input = stdin.readline().strip()

if input == "":
    print(0)
    exit()

i = 1
for char in input:
    if char == ' ':
        i += 1

print(i)