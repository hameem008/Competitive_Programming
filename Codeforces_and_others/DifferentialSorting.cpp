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
    if (v[n - 1] > v[n])
    {
        cout << -1 << endl;
    }
    else if (v[n - 1] == v[n] && v[n] >= 0)
    {
        cout << n - 2 << endl;
        for (i = 1; i <= n - 2; i++)
        {
            cout << i << gap << n - 1 << gap << n << endl;
        }
    }
    else
    {
        if (v[n] < 0)
        {
            flag = true;
            for (i = 1; i <= n - 1; i++)
            {
                if (v[i] > v[i + 1])
                    flag = false;
            }
            if (flag)
                cout << 0 << endl;
            else
                cout << -1 << endl;
        }
        else
        {
            cout << n - 2 << endl;
            for (i = 1; i <= n - 2; i++)
            {
                cout << i << gap << n - 1 << gap << n << endl;
            }
        }
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