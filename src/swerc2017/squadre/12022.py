from sys import stdin, stdout
t = int(stdin.readline())
f = [1] * 20
for k in range(1, 13):
    f[k] = k * f[k - 1]
g = 0
def ans(l, s):
    '''
    l in numero rimasto
    s la risposta
    '''
    global g
    if l == 0:
        g += s
    else:
        for i in range(1, l+1):
            ans(l - i, s // f[i])
for tc in range(t):
    n = int(stdin.readline())
    g = 0
    ans(n, f[n])
    print(g)
