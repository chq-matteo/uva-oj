from sys import stdout
import itertools
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)
stdout.write(str(' ').rjust(3))

for i in range(1, 21):
    stdout.write(str(i).rjust(3))
for i in range(1, 21):
    stdout.write('\n')
    stdout.write(str(i).rjust(3))
    for j in range(1, 21):
        stdout.write(str(1 if gcd(j, i) == 1 else ' ').rjust(3))
    
print()

for i in range(7, 10):
    for t in itertools.product(range(2, 21), repeat=i):
        can = True
        for k in range(len(t)):
            for j in range(k):
                if gcd(t[k], t[j]) != 1 or t[k] < t[j]:
                    can = False
        if can:
            print t