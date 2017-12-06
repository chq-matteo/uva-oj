from sys import stdin, stdout
import queue
t = int(stdin.readline())
for tc in range(t):
    n, m = [int(x) for x in stdin.readline().split()]
    pq = []
    l = queue.deque((int(x), i) for x, i in zip(stdin.readline().split(), range(n)))
    c = [0] * 10
    r = [0] * 10

    for x, i in l:
        c[x] += 1
    for i in range(len(c) - 1):
        r[len(r) - i - 2] = r[len(r) - i - 1] + c[len(r) - i - 1] 

    ans = 0
    while len(l) != 0:
        x, i = l.popleft()
        if r[x] > 0:
            l.append((x, i))
        else:
            ans += 1
            if i == m:
                break
            for j in range(x):
                r[j] -= 1
    stdout.write('{}\n'.format(ans))