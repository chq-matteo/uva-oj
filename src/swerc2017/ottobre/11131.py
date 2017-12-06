from sys import stdin, stdout
import sys
sys.setrecursionlimit(11000)
g = dict()
seq = dict()
def dfs(x):
    if x in g:
        for w in seq[x]:
            dfs(g[x][w])
        seq[x] = seq[x][::-1]
            
    stdout.write(x + '\n')
first = True

for line in stdin:
    f = line.strip().split(',')
    if first:
        root = f[0]
        first = False
    g[f[0]] = f[1:]
    seq[f[0]] = [i for i, _ in zip(range(len(f[1:])), f[1:])]
stdout.write('2\n\n')
dfs(root)
stdout.write('\n')
dfs(root)
