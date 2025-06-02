import numpy as np
import matplotlib.pyplot as plt
n = 3
x = [600, 1800, 2000]
y = [20, 270, 1200]
# x = [0.69, 0.95, 1.13, 1.57, 1.91]
# y = [0.18, 0.2, 0.23, 0.25, 0.31]
# x = [0, 0.01, 0.03, 0.05, 0.07, 0.09, 0.11, 0.13, 0.15, 0.17, 0.19, 0.21]
# y = [1, 1.03, 1.06, 1.38, 2.09, 3.54, 6.41, 12.6, 22.1, 39.05, 65.32, 99.78]
# x = [0, 5, 10, 15, 20, 25, 30]
# y = [1000, 550, 316, 180, 85, 56, 31]
# x = [1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000]
# y = [10.3, 13.5, 13.9, 14.2, 11.6, 10.3, 9.7, 9.6, 14.1, 19.8, 31.1]
# x = [80, 40, -40, -120, -200, -280, -340]
# y = [6.47, 6.24, 5.72, 5.09, 4.30, 3.33, 2.45]
# for i in range(n):
#     a = int(input())
#     b = int(input())
#     x.append(a)
#     y.append(b)
x = np.array(x, float)
y = np.array(y, float)


def linear_model(x, y, n):
    af = np.linspace(min(x), max(x), 100)
    sumx = sum(x)
    sumy = sum(y)
    sumx2 = sum(x**2)
    sumxy = sum(x*y)
    a1 = (n*sumxy-sumx*sumy)/(n*sumx2-sumx**2)
    a0 = sumy/n-a1*sumx/n
    bf = a0 + a1*af
    plt.plot(af, bf)


def exponential_model(x, y, n):
    af = np.linspace(min(x), max(x), 100)
    y = np.log(y)
    sumx = sum(x)
    sumy = sum(y)
    sumx2 = sum(x**2)
    sumxy = sum(x*y)
    a1 = (n*sumxy-sumx*sumy)/(n*sumx2-sumx**2)
    a0 = sumy/n-a1*sumx/n
    a = np.e**a0
    b = a1
    bf = a*np.e**(b*af)
    plt.plot(af, bf)


def saturation_growth_model(x, y, n):
    af = np.linspace(min(x), max(x), 100)
    y = 1/y
    x = 1/x**2
    sumx = sum(x)
    sumy = sum(y)
    sumx2 = sum(x**2)
    sumxy = sum(x*y)
    a1 = (n*sumxy-sumx*sumy)/(n*sumx2-sumx**2)
    a0 = sumy/n-a1*sumx/n
    a = 1/a0
    b = a1*a
    bf = a*af**2/(b+af**2)
    plt.plot(af, bf)


def power_model(x, y, n):
    af = np.linspace(min(x), max(x), 100)
    y = np.log(y)
    x = np.log(x)
    sumx = sum(x)
    sumy = sum(y)
    sumx2 = sum(x**2)
    sumxy = sum(x*y)
    a1 = (n*sumxy-sumx*sumy)/(n*sumx2-sumx**2)
    a0 = sumy/n-a1*sumx/n
    a = np.e**a0
    b = a1
    bf = a*af**b
    plt.plot(af, bf)


def GaussianElimination(A, B):
    n = len(B)
    x = np.zeros(n, float)
    for i in range(n):
        sw = i
        for j in range(i+1, n):
            if abs(A[sw][i]) < abs(A[j][i]):
                sw = j
        A[[i, sw]] = A[[sw, i]]
        B[i], B[sw] = B[sw], B[i]
    for i in range(n-1):
        for j in range(i+1, n):
            if A[j, i] == 0:
                continue
            factor = A[j, i]/A[i, i]
            A[j] = A[j]-A[i]*factor
            B[j] = B[j]-B[i]*factor
    x[n-1] = B[n-1]/A[n-1, n-1]
    for i in range(n-2, -1, -1):
        sum = B[i]
        for j in range(n-1, i, -1):
            sum -= A[i, j]*x[j]
        x[i] = sum/A[i, i]
    return x


def polynomial_model(x, y, n, m):
    af = np.linspace(min(x), max(x), 100)
    mem = []
    mem.append(n)
    A = np.zeros(shape=(m, m))
    for i in range(m):
        for j in range(m):
            l = i+j
            if l != 0:
                if len(mem) > l:
                    A[i][j] = mem[l]
                else:
                    ins = sum(x**l)
                    A[i][j] = ins
                    mem.append(ins)
            else:
                A[i][j] = mem[l]
    B = np.zeros(shape=(m))
    for i in range(m):
        B[i] = sum(y*x**i)
    a = GaussianElimination(A, B)
    bf = np.zeros(shape=(len(af)))
    for i in range(len(a)):
        bf += a[i]*af**i
    plt.plot(af, bf)


# linear_model(x, y, n)
exponential_model(x, y, n)
# saturation_growth_model(x, y, n)
# power_model(x, y, n)
# polynomial_model(x, y, n, 2)
plt.plot(x, y, 'ro')
plt.grid()
plt.show()
