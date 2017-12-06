from sys import stdin, stdout
n, m = [int(x) for x in stdin.readline().split()]
a = [int(x) for x in stdin.readline().split()]
for i in range(m):
    x, y, z = stdin.readline().split()
    y = int(y)
    z = int(z)
    if x == 'M':
        a[y] = z
    else:
        print(len(set(a[y:z])))