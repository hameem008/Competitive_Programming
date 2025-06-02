#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    ll sum1 = 0, sum2 = 0;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        if (p < 0)
            sum2 += p;
        else
            sum1 += p;
    }
    sum2 = (-1) * sum2;
    if (sum1 > sum2)
        cout << sum1 - sum2 << endl;
    else
        cout << sum2 - sum1 << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}