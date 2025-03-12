import sys


def check(value):
    if value == 0:
        print("0")
    elif value < 0:
        print("-")
    else:
        print("+")


value1, value2, value3 = 0, 0, 0

n = int(sys.stdin.readline())
for _ in range(n):
    value1 += int(sys.stdin.readline())

m = int(sys.stdin.readline())
for _ in range(m):
    value2 += int(sys.stdin.readline())

k = int(sys.stdin.readline())
for _ in range(k):
    value3 += int(sys.stdin.readline())

check(value1)
check(value2)
check(value3)
