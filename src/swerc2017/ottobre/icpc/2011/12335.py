from sys import stdin, stdout
t = int(stdin.readline())
f = [1] * 22
for i in range(1, 22):
    f[i] = i * f[i-1]
def permute(s, n):
    if len(s) == 1:
        return s[0]
    # print n // f[len(s) - 1]
    # print s[1:]
    l = permute(s[1:], n % f[len(s) - 1])
    # print l
    ans = l[:n // f[len(s) - 1]] + s[0] + l[n // f[len(s) - 1]:]
    # print ans
    return ans
                
for i in range(t):
    s, n = stdin.readline().split()
    n = int(n)
    s = list(s)
    stdout.write('Case {}: {}\n'.format(i + 1, permute(s, n-1)))