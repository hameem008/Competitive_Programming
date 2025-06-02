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
    vector<ll> v(n + 1, 0);
    for (i = 0; i < n; i++)
    {
        cin >> p;
        v[p]++;
    }
    ll count = 0;
    for (i = 1; i <= n; i++)
    {
        if (v[i] == 0)
            count++;
    }
    if (count == n - 2)
        cout << (n + 2) / 2 << endl;
    else
        cout << n << endl;
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