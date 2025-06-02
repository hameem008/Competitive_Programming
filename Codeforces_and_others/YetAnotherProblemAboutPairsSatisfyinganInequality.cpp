#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    vector<pair<ll, ll>> valid;
    for (i = 1; i <= n; i++)
    {
        if (i > v[i])
            valid.push_back({v[i], i});
    }
    indexed_multiset ms;
    for (auto x : valid)
    {
        ms.insert(x.first);
    }
    ll ans = 0;
    for (auto x : valid)
    {
        ms.erase(ms.find(x.first));
        auto it = ms.lower_bound(x.second);
        if (it != ms.end())
        {
            a = ms.order_of_key(*it);
            b = ms.size();
            ans += (b - a);
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}