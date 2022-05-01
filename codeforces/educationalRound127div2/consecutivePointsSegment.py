for i in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))
    print('YES' if x[-1] - x[0] - n + 1 <= 2 else 'NO')
