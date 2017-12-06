from sys import stdin, stdout
t = int(stdin.readline())
def is_pali(q, a, b):
    while a <= b:
        if q[a] != q[b]:
            return a, b
        a += 1
        b -= 1
    return True
for tc in range(t):
    s = list(stdin.readline().strip())
    d = {c: 0 for c in s}
    for c in s:
        d[c] += 1
    ans = 0
    for k in d:
        ans += 2 ** d[k]
    
    if p == True:
        ans += 2**((y - x) // 2)