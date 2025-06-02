#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    ll ind_n, ind_1, ind_2;
    for (i = 1; i <= n; i++)
    {
        if (v[i] == 1)
            ind_1 = i;
        if (v[i] == n)
            ind_n = i;
        if (v[i] == 2)
            ind_2 = i;
    }
    if (ind_1 == 1 || ind_1 == n)
    {
        if (ind_1 == 1)
        {
            cout << 2 << gap << ind_n << endl;
        }
        else if (ind_1 == n)
        {
            cout << n - 1 << gap << ind_n << endl;
        }
    }
    else
    {
        if (ind_1 > ind_2 && ind_2 > ind_n)
        {
            cout << ind_2 << gap << ind_n << endl;
        }
        else if (ind_1 < ind_2 && ind_2 < ind_n)
        {
            cout << ind_2 << gap << ind_n << endl;
        }
        else if (ind_1 > ind_2 && ind_1 < ind_n)
        {
            cout << ind_1 << gap << ind_n << endl;
        }
        else if (ind_1 > ind_n && ind_1 < ind_2)
        {
            cout << ind_1 << gap << ind_n << endl;
        }
        else
            cout << ind_1 << gap << ind_1 << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}