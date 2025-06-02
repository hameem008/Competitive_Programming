#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

pair<ll, ll> comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first < b.first)
        return a;
    else if (a.first > b.first)
        return b;
    else if (a.second > b.second)
        return a;
    else if (a.second < b.second)
        return b;
    else
        return a;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(powl(2, n) + 1, infinite));
    vector<vector<ll>> cap(n + 1, vector<ll>(powl(2, n) + 1, -1));
    vector<vector<ll>> mp(n + 1);
    for (i = 0; i < powl(2, n); i++)
    {
        mp[__builtin_popcount(i)].push_back(i);
    }
    dp[0][0] = 0;
    cap[0][0] = m;
    for (i = 1; i <= n; i++)
    {
        for (auto x : mp[i])
        {
            j = x;
            for (k = 0; k < n; k++)
            {
                if ((j & (1 << k)))
                {
                    ll prev = dp[i - 1][(j ^ (1 << k))];
                    ll prev_cap = cap[i - 1][(j ^ (1 << k))];
                    pair<ll, ll> p1 = {infinite, -1}, p2 = {dp[i][j], cap[i][j]}, p;
                    if (prev <= dp[i][j])
                    {
                        if (prev_cap - v[k] < 0)
                        {
                            p1.first = prev + 1;
                            p1.second = m - v[k];
                        }
                        else
                        {
                            p1.first = prev;
                            p1.second = prev_cap - v[k];
                        }
                    }
                    p = comp(p1, p2);
                    dp[i][j] = p.first;
                    cap[i][j] = p.second;
                }
            }
        }
    }
    cap[n][powl(2, n) - 1] == m ? cout << dp[n][powl(2, n) - 1] << endl : cout << dp[n][powl(2, n) - 1] + 1 << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}