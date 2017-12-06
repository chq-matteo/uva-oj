from sys import stdin, stdout
t = []
s = dict()
for i in range(16):
    t.append(stdin.readline().strip())
    s[t[i]] = i
m = []
for i in range(16):
    m.append([float(x) / 100 for x in stdin.readline().strip().split()])
p1 = []
p2 = [0] * 16
p3 = [0] * 16
p4 = [0] * 16

for i in range(0, 16, 2):
    p1.append(m[i][i+1])
    p1.append(m[i+1][i])
# print (p1)
# print(sum(p1))
for q in range(4):
    b = 4 * q
    for j in range(4):
        pw = 0
        for k in range(4):
            if j // 2 != k // 2:
                pw += p1[b + k] * m[b + j][b + k]
        p2[b + j] = pw * p1[b + j]
# print(p2)
for q in range(2):
    b = 8 * q
    for j in range(8):
        pw = 0
        for k in range(8):
            if j // 4 != k // 4:
                pw += p2[b + k] * m[b + j][b + k]
        p3[b + j] = pw * p2[b + j]
# print(p3)
for j in range(16):
    pw = 0
    for k in range(16):
        if j // 8 != k // 8:
            pw += p3[k] * m[j][k]
    p4[j] = pw * p3[j]
# print(p4)
# print(sum(p4))
for i in range(16):
    print('{:10} p={:.02f}%'.format(t[i], p4[i] * 100))