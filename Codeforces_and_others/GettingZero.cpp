#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

set<ll> twopower;

void precom()
{
    for (int i = 1; i <= 15; i++)
    {
        twopower.insert(pow(2, i));
    }
}

ll divby2(ll n)
{
    register ll ans = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        ans++;
    }
    return ans;
}

void solve(int I, int T)
{
    register ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    register vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    register vector<ll> ans;
    for (i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            ans.push_back(0);
        }
        else
        {
            register ll limit = *twopower.upper_bound(v[i]);
            register ll op = 15;
            for (j = v[i]; j <= limit; j++)
            {
                if (op > (15 - divby2(j) + j - v[i]))
                    op = 15 - divby2(j) + j - v[i];
            }
            ans.push_back(op);
        }
    }
    for (auto x : ans)
        cout << x << gap;
    cout << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precom();
    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}