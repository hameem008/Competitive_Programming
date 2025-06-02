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
    ll coins;
    cin >> n >> coins;
    vector<ll> v(n), addition(n), costs;
    for (auto &x : v)
        cin >> x;
    for (i = 0; i < n; i++)
    {
        addition[i] = min(i + 1, n - i);
    }
    for (i = 0; i < n; i++)
    {
        costs.push_back(addition[i] + v[i]);
    }
    sort(costs.begin(), costs.end());
    vector<ll> presum(costs.begin(), costs.end());
    for (i = 1; i < n; i++)
    {
        presum[i] += presum[i - 1];
    }
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        ll temp_coins = coins, temp_ans = 0;
        if (temp_coins >= v[i] + i + 1)
        {
            temp_coins -= (v[i] + i + 1);
            temp_ans = upper_bound(presum.begin(), presum.end(), temp_coins) - presum.begin();
            ll ind = lower_bound(costs.begin(), costs.end(), v[i] + addition[i]) - costs.begin();
            if (temp_ans > ind)
            {
                temp_coins += v[i] + addition[i];
                temp_ans = upper_bound(presum.begin(), presum.end(), temp_coins) - presum.begin();
            }
            else
            {
                temp_ans++;
            }
        }
        ans = max(temp_ans, ans);
    }
    cout << ans << endl;
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