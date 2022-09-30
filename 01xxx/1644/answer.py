from bisect import bisect_right
import math

N = int(input())

# 1. Sieve of Eratosthenes
table = [True] * ((N // 2) + 1)
table[0] = False
for i in range(3, int(math.sqrt(N)) + 2, 2):
    if table[i // 2] == False:
        continue
    for j in range(i ** 2, len(table) * 2, i * 2):
        table[j // 2] = False

# 2. Write a list for primes
primeList = [2]
for i in range(len(table)):
    if table[i] is True:
        primeList.append(i * 2 + 1)

# 3. Binary search for continuous prime list of length k which has sum N, for all the possible value of k
ans = 0
for k in range(1, 1040):
    startRange = 0
    endRange = bisect_right(primeList, N // k + 1) - 1
    target = (startRange + endRange) // 2
    if endRange <= 0:
        break
    while True:
        targetSum = sum(primeList[target:target+k])
        if targetSum == N:
            ans += 1
            break
        elif targetSum > N:
            endRange = target
        else:
            startRange = target
        target = (startRange + endRange) // 2
        if startRange == target or endRange == target:
            startSum = sum(primeList[startRange:startRange+k])
            endSum = sum(primeList[endRange:endRange+k])
            if startSum == N or endSum == N:
                ans += 1
            break
    if target == 0:
        break

print(ans)