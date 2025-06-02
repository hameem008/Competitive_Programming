import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt("dissolveO2.csv", delimiter=",", skip_header=1)

temperature = data[:, 0]
solubility_1 = data[:, 1]
solubility_2 = data[:, 2]

temp = float(input("Type "))

for i in range(temperature.size):
    if (temp >= temperature[i] and temp <= temperature[i+1]):
        low_ind = i
        high_ind = i+1
        break


def Lt(per, ind, x, n):
    ans = 1
    for i in range(n):
        if i != ind:
            ans = ans*(per-x[i])/(x[ind]-x[i])
    return ans


def func(per, x, y, n):
    ans = 0
    for i in range(n):
        ans = ans+Lt(per, i, x, n)*y[i]
    return ans


if (high_ind+1 >= temperature.size):
    low_ind -= 2
    x = temperature[low_ind:high_ind+1]
    y = solubility_1[low_ind:high_ind+1]
    print("ans1 = ", func(temp, x, y, 3))
    print("error1 = ", 100*abs(func(temp, x, y, 3) -
          func(temp, x, y, 4))/func(temp, x, y, 4))
    plt.plot(temp, func(temp, x, y, 3), 'ro')
    y = solubility_2[low_ind:high_ind+1]
    print("ans2 = ", func(temp, x, y, 3))
    print("error2 = ", 100*abs(func(temp, x, y, 3) -
          func(temp, x, y, 4))/func(temp, x, y, 4))
    plt.plot(temp, func(temp, x, y, 3), 'ro')
elif (low_ind == 0):
    high_ind += 2
    x = temperature[low_ind:high_ind+1]
    y = solubility_1[low_ind:high_ind+1]
    print("ans1 = ", func(temp, x, y, 3))
    print("error1 = ", 100*abs(func(temp, x, y, 3) -
          func(temp, x, y, 4))/func(temp, x, y, 3))
    plt.plot(temp, func(temp, x, y, 3), 'ro')
    y = solubility_2[low_ind:high_ind+1]
    print("ans2 = ", func(temp, x, y, 3))
    print("error2 = ", 100*abs(func(temp, x, y, 3) -
          func(temp, x, y, 4))/func(temp, x, y, 4))
    plt.plot(temp, func(temp, x, y, 3), 'ro')
else:
    low_ind -= 1
    high_ind += 1
    x = temperature[low_ind:high_ind+1]
    y = solubility_1[low_ind:high_ind+1]
    print("ans1 = ", func(temp, x, y, 3))
    print("error1 = ", 100*abs(func(temp, x, y, 3) -
          func(temp, x, y, 4))/func(temp, x, y, 3))
    plt.plot(temp, func(temp, x, y, 3), 'ro')
    y = solubility_2[low_ind:high_ind+1]
    print("ans2 = ", func(temp, x, y, 3))
    print("error2 = ", 100*abs(func(temp, x, y, 3) -
          func(temp, x, y, 4))/func(temp, x, y, 4))
    plt.plot(temp, func(temp, x, y, 3), 'ro')

plt.plot(temperature, solubility_1)
plt.plot(temperature, solubility_2)
plt.show()
