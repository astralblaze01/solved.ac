arr = []
for i in range(5):
    value = int(input())
    arr.append(value)

result = 0
for i in range(5):
    if(arr[i] < 40):
        arr[i] = 40
    result = arr[i] + result


print(int(result / 5))
