from sys import stdin, stdout
import sys
sys.setrecursionlimit(11000)
t = int(stdin.readline())
def dfs(s, i, p, d):
    if p in d:
        d[p].append(s[i])
    else:
        d[p] = [s[i]]
    if s[i].islower():
        return i+1
    else:
        k = dfs(s, i+1, p+1, d)
        return dfs(s, k, p+1, d)
for tc in range(t):
    line = stdin.readline().strip()[::-1]
    d = dict()
    #print(line)
    dfs(line, 0, 0, d)
    key = max(d.keys())
    stack = [[] for _ in range(key+1)]
    for i in range(key, -1, -1):
        for a in d[i]:
            stdout.write(a)
    stdout.write('\n')
