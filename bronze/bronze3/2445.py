n = int(input())

for i in range(1, n + 1):
    print('*' * i + ' ' * (2 * (n - i)), end='')
    print('*' * i)

for i in range(n - 1, 0, -1):
    print('*' * i + ' ' * (2 * (n - i)), end='')
    print('*' * i)
