from sys import stdin, stdout
t = int(stdin.readline())
p = [1]
for i in range(1, 21):
    p.append(p[i - 1] * i)
for tc in range(t):
    s = sorted(list(stdin.readline().strip()))
    n = int(stdin.readline())
    k = len(s) - 1
    while n > 0:
        stdout.write(s[n // p[k]])
        s = s[:n//p[k]] + s[n//p[k] + 1:]
        n = n % p[k]
        k -= 1
    stdout.write(''.join(s))
    stdout.write('\n')
