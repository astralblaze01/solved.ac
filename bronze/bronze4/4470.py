n = int(input())
arr = []
for i in range(n):
    value = input()
    arr.append(value)

for i in range(n):
    print(str(i + 1) + ". " + arr[i])
