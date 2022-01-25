from sys import stdin

input = int(stdin.readline())
while(input != 0):
    currentValue = input
    while(currentValue > 9):
        k = currentValue
        sum = 0
        while(k > 0):
            sum += k % 10
            k = k // 10
        currentValue = sum
    print(currentValue)
    input = int(stdin.readline())