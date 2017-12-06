from sys import stdin, stdout

while True:
    s = stdin.readline().strip()
    if s == '':
        break
    n = int(s)
    k = sorted([(i, int(x)) for i, x in enumerate(stdin.readline().split())], key=lambda k: (-k[1], -k[0]))
    if len(k) < 2 or k[0][1] > sum(map(lambda x: x[1], k[1:])):
        stdout.write('impossible\n')
    else:
        stdout.write(' '.join([str(x[0] + 1) for x in k]) + '\n')