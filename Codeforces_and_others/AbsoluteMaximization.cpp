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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    for (i = 0; i < 32; i++)
    {
        if (v[0] & (1 << i))
        {
            for (j = 0; j < n; j++)
            {
                if (!(v[j] & (1 << i)))
                {
                    v[0] = v[0] ^ (1 << i);
                    v[j] = v[j] ^ (1 << i);
                    break;
                }
            }
        }
    }
    for (i = 0; i < 32; i++)
    {
        if (!(v[n - 1] & (1 << i)))
        {
            for (j = 0; j < n; j++)
            {
                if (v[j] & (1 << i))
                {
                    v[n - 1] = v[n - 1] ^ (1 << i);
                    v[j] = v[j] ^ (1 << i);
                    break;
                }
            }
        }
    }
    cout << v[n - 1] - v[0] << endl;
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