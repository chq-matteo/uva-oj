'''
124 Following Orders
Topological Sort

We track a set of "good" variables that are free to be picked in that moment
We recoursively make a copy of this set and pick each of them, one at a time and then update the good variables
When we have picked all the variables we print them out and backtrack
'''
from sys import stdin, stdout
alpha = set('asqxwczdevrftbghynumijklop')
first = True
while True:
    line = stdin.readline()
    if line == '':
        break
    if first:
        first = False
    else:
        stdout.write('\n')
        
    v = sorted([q for q in list(line) if q in alpha])
    translation = {v[i]: i for i in range(len(v))}
    line = stdin.readline()    
    c = [q for q in list(line) if q in alpha]
    # a before b
    abb = [set() for i in range(len(v))]
    # a after b
    aab = [set() for i in range(len(v))]
    for i in range(0, len(c), 2):
        abb[translation[c[i]]].add(translation[c[i+1]])
        aab[translation[c[i+1]]].add(translation[c[i]])
    good = set()
    picked = []
    for i in range(len(v)):
        if len(aab[i]) == 0:
            good.add(i)
    # print (good)
    def try_all():
        if len(picked) == len(v):
            stdout.write(''.join([v[p] for p in picked]))
            stdout.write('\n')
        else:
            okay = set(good)
            for g in okay:
                if g in good:
                    good.remove(g)
                picked.append(g)
                coup = []
                toogood = set()
                for after in abb[g]:
                    if g in aab[after]:
                        coup.append((after, g))
                        aab[after].remove(g)
                        if len(aab[after]) == 0:
                            good.add(after)
                            toogood.add(after)
                try_all()
                for c in coup:
                    aab[c[0]].add(c[1])
                for tg in toogood:
                    if tg in good:
                        good.remove(tg)
                picked.pop()
                good.add(g)
    try_all()
