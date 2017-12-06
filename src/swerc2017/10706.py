s = []
m = ''
sm = 0
from sys import stdin, stdout
for i in range(1, 10200000):
    m += str(i)
    s.append(len(m))
    sm += len(m)
    if sm > 2147483647:
        break
# print(m[:100])
# print(s[:100])
print(len(s))
t = int(stdin.readline())
for j in range(t):
    k = int(stdin.readline())
    q = 0
    while k > s[q]:
        # print(k)
        k -= s[q]
        q += 1
    print(m[k-1])
# print(len(s))
# print(len(m))
# import random
# for i in range(25):
# 
#     k = random.randint(0, 2000000000)
#     q = 0
#     while k > s[q]:
#         k -= s[q]
#         q += 1
#     print(m[k])
# 