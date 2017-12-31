# 10940 Throwing cards away II
# helper script to better understand the problem
import queue
for i in range(1, 201):
    l = queue.deque(range(1, i + 1))
    print()
    print(bin(i))
    while len(l) > 0:
        if len(l) == 1:
            k = l.popleft()
            print(bin(k))
            print(k)
        else:
            l.popleft()
        if len(l) > 0:
            l.append(l.popleft())
