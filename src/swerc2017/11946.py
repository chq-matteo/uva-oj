from sys import stdin, stdout
t = int(stdin.readline())
d = '0123456789'
e = 'OIZEASGTBP'
D = {d[i]: e[i] for i in range(len(d))}
s = stdin.readline()

while s != '':
    for i in range(len(s)):
        if s[i] in D:
            stdout.write(D[s[i]])
        else:
            stdout.write(s[i])
    s = stdin.readline()