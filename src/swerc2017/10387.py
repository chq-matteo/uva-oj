from sys import stdin, stdout
import math
tmp = '{:.2f} {:.2f}\n'
for line in stdin:
    a, b, s, m, n = [int(x) for x in line.split()]
    if (a, b, s, m, n) == (0, 0, 0, 0, 0):
        break
    l = 0
    m *= 1000000
    n *= 1000000
    if m == 0 and n == 0:
        stdout.write(tmp.format(0, 0))
    elif m == 0:
        stdout.write(tmp.format(0, a*n / s))
    elif n == 0:
        stdout.write(tmp.format(90, b*n / s))
    else:
        l = math.gcd(m, n)
        # print(l)
        h = 0
        y = 0
        if m > n:
            h = (l * b / 2) / n # 0 <= h <= a/2
            y = math.sqrt(a*a / 4 + h*h)
            # print((a*a / 4 + h*h))
            # print(h, y)
            # print(math.asin(h / y) / math.pi * 180)
            # print(h / y)
            # print(y)
            print(h, y, math.asin(h / y))
            
            ang = (math.asin(h / y) * 2 / math.pi) * 90
            stdout.write(tmp.format(ang, 2 * (y * m) / s))
        else:
            h = (l * a / 2) / m
            y = math.sqrt(b*b / 4 + h*h)
            # print(b*b)
            # print((b*b / 4 + h*h))
            
            # print(h, y
            # )
            # print('ciao' + str(math.asin(h / y) / math.pi * 180))
            ang = (math.asin(h / y) * 2 / math.pi * 90)
            stdout.write(tmp.format(ang, 2 * (y * n) / s))
