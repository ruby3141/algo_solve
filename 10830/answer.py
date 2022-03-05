from sys import stdin
from typing import List

def SquareMatrixMultiplyMod1000(matrix1: List[List[int]], matrix2: List[List[int]]) -> List[List[int]]:
    return [[sum(matrix1[i][k] * matrix2[k][j] for k in range(len(matrix1))) % 1000 for j in range(len(matrix2[0]))] for i in range(len(matrix1))]

def GetBitPositions(number: int) -> List[int]:
    positions = []
    mask = 1
    index = 1
    while number > 0:
        if number & mask > 0:
            positions.append(index)
        number >>= 1
        index += 1
    return positions

N, B = [int(x) for x in stdin.readline().split()]
M = [[int(x) for x in stdin.readline().split()] for _ in range(N)]

BitPosition = GetBitPositions(B)
MaxIter = max(BitPosition)

PoweredMatrix = [[[1 if i == j else 0 for j in range(N)] for i in range(N)], M]
for i in range(2, MaxIter + 1):
    PoweredMatrix.append(SquareMatrixMultiplyMod1000(PoweredMatrix[i - 1], PoweredMatrix[i - 1]))

answer = PoweredMatrix[0]
for bit in BitPosition:
    answer = SquareMatrixMultiplyMod1000(answer, PoweredMatrix[bit])

[[print(answer[i][j], end = ' ' if j != N - 1 else '\n') for j in range(N)] for i in range(N)]
