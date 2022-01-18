from sys import stdin
word = stdin.readline().strip()
word = word.upper()

chardic = {}
for char in word:
    if char in chardic:
        chardic[char] += 1
    else:
        chardic[char] = 1

maxvalue = max(chardic.values())
maxchar = '?'
for k, v in chardic.items():
    if v == maxvalue:
        if maxchar != '?':
            print("?")
            exit()
        else:
            maxchar = k

print(maxchar)