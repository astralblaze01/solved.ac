n = int(input())

arr = []
for i in range(n):
    value = int(input())
    arr.append(value)
arr.sort()

for i in range(n):
    print(arr[i])
