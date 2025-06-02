#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> a >> b >> c >> d;
    ll la = a, lb = b;
    vector<pair<ll, ll>> av, bv;
    ll limit = sqrt(a) + 1;
    for (i = 1; i <= limit; i++)
    {
        if (a % i == 0)
            av.push_back({i, a / i});
    }
    limit = sqrt(b) + 1;
    for (i = 1; i <= limit; i++)
    {
        if (b % i == 0)
            bv.push_back({i, b / i});
    }
    pair<ll, ll> ans = {-1, -1};

    m = c / a;
    m *= a;
    n = d / b;
    n *= b;
    p = c / b;
    p *= b;
    q = d / a;
    q *= a;
    if (m > la && n > lb)
    {
        ans = {m, n};
        cout << ans.first << gap << ans.second << endl;
        return;
    }
    if (p > la && q > lb)
    {
        ans = {p, q};
        cout << ans.first << gap << ans.second << endl;
        return;
    }
    if (ans.first == -1 && ans.second == -1)
    {
        for (auto x : av)
        {
            for (auto y : bv)
            {
                a = x.first * y.first;
                b = x.second * y.second;
                m = c / a;
                m *= a;
                n = d / b;
                n *= b;
                p = c / b;
                p *= b;
                q = d / a;
                q *= a;
                if (m > la && n > lb)
                {
                    ans = {m, n};
                    cout << ans.first << gap << ans.second << endl;
                    return;
                }
                if (p > la && q > lb)
                {
                    ans = {p, q};
                    cout << ans.first << gap << ans.second << endl;
                    return;
                }
                a = x.first * y.second;
                b = x.second * y.first;
                m = c / a;
                m *= a;
                n = d / b;
                n *= b;
                p = c / b;
                p *= b;
                q = d / a;
                q *= a;
                if (m > la && n > lb)
                {
                    ans = {m, n};
                    cout << ans.first << gap << ans.second << endl;
                    return;
                }
                if (p > la && q > lb)
                {
                    ans = {p, q};
                    cout << ans.first << gap << ans.second << endl;
                    return;
                }
            }
        }
    }
    cout << ans.first << gap << ans.second << endl;
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