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
    vector<pair<ll, ll>> vp;
    set<ll> s;
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b;
        s.insert(a);
        s.insert(b);
        vp.push_back({a, b});
    }
    sort(vp.begin(), vp.end());
    unordered_map<ll, ll> mp;
    i = 1;
    for (auto x : s)
    {
        mp[x] = i;
        i++;
    }
    vector<pair<ll, ll>> dum_vp;
    unordered_map<ll, bool> done;
    for (auto x : vp)
    {
        if (!done[x.first])
        {
            dum_vp.push_back(x);
            done[x.first] = true;
        }
    }
    vp = dum_vp;
    vector<ll> dp(i + 8, 0);
    for (auto x : vp)
    {
        dp[mp[x.first]]++;
    }
    vector<ll> ending_time(i + 8, 0);
    for (auto x : vp)
    {
        ending_time[mp[x.first]] = mp[x.second];
    }
    for (i = dp.size() - 2; i >= 0; i--)
    {
        if (dp[i])
        {
            dp[i] += dp[ending_time[i]];
            dp[i] = max(dp[i], dp[i + 1]);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }
    cout << dp[0] << endl;
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