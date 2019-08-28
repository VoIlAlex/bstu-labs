import sys

if len(sys.argv) == 1:
    n = 5
else:
    n = int(sys.argv[1])

for i in range(100):
    print('{0}^{1}(mod {1}): {2}\t\t{0}(mod {1}): {3}'.format(i, n, (i ** n)%n, i % n))

