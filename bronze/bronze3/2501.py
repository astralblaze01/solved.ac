a, b = map(int, input().split())

arr = []
for i in range(1, a + 1):
    if a % i == 0:
        arr.append(i)

# print(arr)
if(len(arr) < b):
    print("0")
else:

    print(arr[b-1])
