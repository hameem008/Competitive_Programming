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
    cin >> n >> m >> k;
    ll tpp, mana;
    cin >> tpp >> mana;
    vector<pair<ll, ll>> spell1(m), spell2(k);
    for (auto &x : spell1)
    {
        cin >> x.second;
    }
    for (auto &x : spell1)
    {
        cin >> x.first;
    }
    spell1.push_back({0, tpp});
    for (auto &x : spell2)
    {
        cin >> x.second;
    }
    for (auto &x : spell2)
    {
        cin >> x.first;
    }
    set<pair<ll, ll>> spell2_set(spell2.begin(), spell2.end());
    ll ans = tpp * n;
    for (auto x : spell1)
    {
        if (x.first <= mana)
        {
            auto it = spell2_set.lower_bound({mana - x.first + 1, 0});
            if (it != spell2_set.begin())
            {
                it--;
                ans = min(ans, (n - it->second) * x.second);
            }
            else
            {
                ans = min(ans, n * x.second);
            }
        }
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}