import numpy as np
import matplotlib.pyplot as plt

x = np.array([22, 25, 28])
y = np.array([37.98, 57.25, 41.87])


def recursion(high, low):
    if (high-low == 1):
        return (y[high]-y[low])/(x[high]-x[low])
    return (recursion(high, low+1)-recursion(high-1, low))/(x[high]-x[low])


def equation(per):
    ans = y[0]
    mult = 1
    for i in range(2):
        mult = mult*(per-x[i])
        ans = ans+recursion(i+1, 0)*mult
    return ans


print(equation(24))
plt.plot(x, y, 'ro')
plt.plot(x, y)
plt.show()
