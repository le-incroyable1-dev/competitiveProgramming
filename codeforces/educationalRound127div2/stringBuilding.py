t = int(input())
for i in range(t):
    s = input()
    ans = True
    n = len(s)
    for j in range(n):
        if (j == 0 or s[j] != s[j - 1]) and (j == n - 1 or s[j] != s[j + 1]):
            ans = False
    print('YES' if ans else 'NO')
