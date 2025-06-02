#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

double eps = 1e-6;

double multiply(double d, int n)
{
    double multi = d;
    for (int i = 0; i < n; i++)
    {
        multi = multi * d;
    }
    return multi;
}

int main()
{
    double x;
    cin >> x;
    double lo = 1, hi = x, mid;
    while (hi - lo > eps)
    {
        mid = (hi + lo) / 2;

        if (pow(mid, 3) < x)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    cout << lo << gap << hi << endl;
    cout << pow(x, 1.0 / 3) << endl;
}