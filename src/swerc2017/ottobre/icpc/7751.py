def eq(i, j, l, k):
    return i**2 + j**2 + l**2 == k*(i*j + j*l + i*l) + 1
i, j, l = 1, 1, 1
while i < 100:
    j, l = i + 1, i
    while j < 100:
        l = j + 1
        while l < 100:
            if eq(i, j, l, 2):
                print i, j, l
                i += 1
            l += 1
        j += 1
    i += 1