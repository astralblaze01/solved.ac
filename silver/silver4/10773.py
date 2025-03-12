stack = []
n = int(input())

for i in range(n):
    val = int(input())
    if(val == 0):
        stack.pop()
    else:
        stack.append(val)

print(sum(stack))