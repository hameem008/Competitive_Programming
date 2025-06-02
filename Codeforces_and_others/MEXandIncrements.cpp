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
    vector<ll> v(n), dp(n + 1, 0);
    for (auto &x : v)
        cin >> x;
    multiset<ll> ms(v.begin(), v.end());
    map<ll, ll> mp;
    for (i = 0; i <= n; i++)
    {
        if (ms.count(i) > 1)
            mp[i] = ms.count(i) - 1;
    }
    dp[0] = ms.count(0);
    for (i = 1; i <= n; i++)
    {
        if (dp[i - 1] == -1)
            dp[i] = -1;
        else
        {
            if (ms.count(i - 1) > 0)
            {
                dp[i] = dp[i - 1] - ms.count(i - 1) + ms.count(i);
            }
            else
            {
                auto it = mp.lower_bound(i - 1);
                if (it == mp.begin())
                {
                    dp[i] = -1;
                }
                else
                {
                    it--;
                    dp[i] = dp[i - 1] + i - 1 - it->first + ms.count(i);
                    ms.insert(i - 1);
                    ms.erase(ms.find(it->first));
                    it->second--;
                    if (it->second == 0)
                        mp.erase(it);
                }
            }
        }
    }
    for (auto x : dp)
        cout << x << gap;
    cout << endl;
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