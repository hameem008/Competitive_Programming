import numpy as np


def GaussianElimination(A, B, pivot, showall):
    n = len(B)
    x = np.zeros(n, float)
    # pertial pivoting
    if pivot == True:
        for i in range(n):
            for j in range(i+1, n):
                if abs(A[i][i]) < abs(A[j][i]):
                    A[[i, j]] = A[[j, i]]
                    B[i], B[j] = B[j], B[i]
    # forward elemination
    for i in range(n-1):
        for j in range(i+1, n):
            if A[j, i] == 0:
                continue
            factor = A[j, i]/A[i, i]
            A[j] = A[j]-A[i]*factor
            B[j] = B[j]-B[i]*factor
        if showall == True:
            print(A)
            print(B)
    # back substitution
    x[n-1] = B[n-1]/A[n-1, n-1]
    for i in range(n-2, -1, -1):
        sum = B[i]
        for j in range(n-1, i, -1):
            sum -= A[i, j]*x[j]
        x[i] = sum/A[i, i]
    return x


n = 4
a = np.array([[3, -2, 5, 0],
              [4, 5, 8, 1],
              [1, 1, 2, 1],
              [2, 7, 6, 5]], float)
b = np.array([2, 4, 5, 7], float)
x = np.zeros(n, float)

print(GaussianElimination(a, b, True, True))

# # pertial pivoting
# for i in range(n):
#     for j in range(i+1, n):
#         if abs(a[i][i]) < abs(a[j][i]):
#             a[[i, j]] = a[[j, i]]
#             b[i], b[j] = b[j], b[i]
# # forward elimination
# for i in range(n-1):
#     for j in range(i+1, n):
#         if a[j, i] == 0:
#             continue
#         factor = a[j, i]/a[i, i]
#         a[j] = a[j]-a[i]*factor
#         b[j] = b[j]-b[i]*factor
#     print(a)

# demo
# for i in range(n-1):
#     for j in range(i+1, n):
#         if a[j, i] == 0:
#             continue
#         factor = a[i, i]/a[j, i]
#         a[j] = a[i]-a[j]*factor
#         b[j] = b[i]-b[j]*factor
# print(a)
# print(b)
# back substitution
# x[n-1] = b[n-1]/a[n-1, n-1]
# for i in range(n-2, -1, -1):
#     sum = b[i]
#     for j in range(n-1, i, -1):
#         sum -= a[i, j]*x[j]
#     x[i] = sum/a[i, i]
# print(x)
