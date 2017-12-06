from sys import stdin, stdout
v = {c: x for c, x in zip(list('abcdefghijklmnopqrstuvwxyz'), range(1, 27))}
def to_num(x):
    ans = 0
    for c in x:
        ans = ans * 32 + v[c]
    return ans
def check(C, w, n):
    for k in w:
        for z in w:
            if k != z and (C // k) % n == (C // z) % n:
                return min((C//k + 1)*k, (C//z + 1)*z)
    return C

for line in stdin:
    w = [to_num(x) for x in line.split()]
    # print(w)
    n = len(w)
    C = 0
    C1 = check(C, w, n)
    while C1 != C:
        C = C1
        C1 = check(C, w, n)
    stdout.write('{}\n{}\n\n'.format(line.strip(), C1))