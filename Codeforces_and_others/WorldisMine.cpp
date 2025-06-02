#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll func(indexed_set<ll> alice, set<pair<ll, ll>> bob, vector<ll> v)
{
    ll ans = 1;
    while (bob.size())
    {
        auto it = bob.begin();
        ll cnt = it->first;
        ll ind = alice.order_of_key(it->second);
        if (cnt <= ind + 1)
        {
            alice.erase(it->second);
            while (cnt--)
            {
                auto iit = alice.begin();
                if (iit == alice.end())
                    break;
                ans++;
                alice.erase(iit);
                bob.erase({v[*iit], *iit});
            }
        }
        bob.erase(it);
    }
    ans += alice.size();
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        v[a]++;
    }
    set<pair<ll, ll>> bob;
    indexed_set<ll> alice;
    for (i = 1; i <= n; i++)
    {
        if (v[i] > 0)
        {
            bob.insert({v[i], i});
            alice.insert(i);
        }
    }
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (v[i] > 0)
        {
            alice.erase(i);
            bob.erase({v[i], i});
            ans = max(ans, func(alice, bob, v));
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