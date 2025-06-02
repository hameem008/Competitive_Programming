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
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    for (i = 0; i < k; i++)
    {
        vector<ll> dum;
        for (j = 0; j <= n / k + 1; j++)
        {
            if (i + j * k < n)
                dum.push_back(v[i + j * k]);
        }
        sort(dum.begin(), dum.end());
        for (j = 0; j <= n / k + 1; j++)
        {
            if (i + j * k < n)
                v[i + j * k] = dum[j];
        }
    }
    ll invers = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
            invers++;
    }
    if (invers == 0)
    {
        cout << 0 << endl;
    }
    else if (invers == 1)
    {
        cout << 1 << endl;
    }
    else if (invers == 2)
    {
        set<ll> ind;
        for (i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                ind.insert(i);
            }
        }
        if (*ind.rbegin() - *ind.begin() <= 2)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
    else
        cout << -1 << endl;
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