from sys import stdin, stdout
from math import ceil
t = int(stdin.readline())
bands = [
    (180000, 0),
    (300000, 0.1),
    (400000, 0.15),
    (300000, 0.20),
    (1000000000, 0.25)]
def tax(income, band):
    if income <= 0:
        return 0
    taxable = min(income, bands[band][0]) * bands[band][1] + tax(income - bands[band][0], band + 1)
    #print taxable
    return taxable
for tc in range(1, t+1):
    k = int(stdin.readline())
    taxable = ceil(tax(k, 0))
    if taxable > 0:
        taxable = max(2000, int(taxable))
    else:
        taxable = 0
    stdout.write('Case {}: {}\n'.format(tc, taxable))
