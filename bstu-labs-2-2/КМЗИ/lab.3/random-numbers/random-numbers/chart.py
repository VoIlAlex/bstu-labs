import matplotlib.pyplot as plt
import sys

if len(sys.argv) != 2:
    print("Something went wrong while chart creation. (Bad arguments)")
    exit(0)

file = open(sys.argv[1], 'r')

values = []
for line in file:
    values.append(int(line))

X = [x for x in range(len(values))]
Y = [sum(values[:i])/i for i in range(1, len(X) + 1)]

plt.plot(X, Y)
plt.title('Average')
plt.show()
