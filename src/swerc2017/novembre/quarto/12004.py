from sys import stdin, stdout
t = int(stdin.readline())
for tc in range(t):
    n = int(stdin.readline())
    ans = n * (n - 1)
    if ans % 4 == 0:
        stdout.write('Case {}: {}\n'.format(tc+1, ans//4))
    elif ans % 2 == 0:
        stdout.write('Case {}: {}/{}\n'.format(tc+1, ans//2, 2))
    else:
        stdout.write('Case {}: {}/{}\n'.format(tc+1, ans, 4))
    