def combination(n, r):
    sum1 = 1
    sum2 = 1

    for i in range(r + 1, n + 1):
        sum1 *= i

    for i in range(1, n - r + 1):
        sum2 *= i

    result = sum1 / sum2

    return result


a, b = map(int, input().split())
print(int(combination(a, b)))
