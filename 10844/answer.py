from sys import stdin

N = int(stdin.readline())
currIter = [1] * 10

while N > 1:
    nextIter = [0] * 10
    for i in range(10):
        if i - 1 >= 0:
            nextIter[i] += currIter[i - 1]
        if i + 1 <= 9:
            nextIter[i] += currIter[i + 1]
    currIter = nextIter
    N -= 1

print(f"{sum(currIter[1:10])}")