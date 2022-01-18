from sys import stdin
A, B = [int(x) for x in stdin.readline().split()]
if A > B:
    print(">")
elif A < B:
    print("<")
else:
    print("==")