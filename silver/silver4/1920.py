def binary_search(target, data):
    start = 0
    end = len(data) - 1

    while start <= end:
        mid = (start + end) // 2

        if data[mid] == target:
            return True
        elif data[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

    return False


k = int(input())
arr1 = list(map(int, input().split()))
n = int(input())
arr2 = list(map(int, input().split()))

arr1.sort()  # arr1 정렬

for i in range(n):
    result = binary_search(arr2[i], arr1)
    if result:
        print("1")
    else:
        print("0")
