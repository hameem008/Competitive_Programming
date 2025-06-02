import numpy as np
import matplotlib.pyplot as plt

x = np.array([10, 15, 20, 22.5])
y = np.array([227.04, 362.78, 517.35, 602.97])


def Lt(per, ind):
    ans = 1
    for i in range(4):
        if i != ind:
            ans = ans*(per-x[i])/(x[ind]-x[i])
    return ans


def func(per):
    ans = 0
    for i in range(4):
        ans = ans+Lt(per, i)*y[i]
    return ans


print(func(16))
