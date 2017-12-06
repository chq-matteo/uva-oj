from sys import stdin, stdout
from fractions import gcd
import math
t = int(stdin.readline())
s = [int(x) for x in stdin.read().strip().split()]
for tc in range(1, t+1):
    a, b = s[2*tc - 2], s[2*tc - 1]
    if a == 0 or b == 0:
        stdout.write('Case {}: {}\n'.format(tc, 1))
    else:
        g = gcd(a, b)
        stdout.write('Case {}: {}\n'.format(tc, (a+b)//g))