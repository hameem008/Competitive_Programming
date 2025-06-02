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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    indexed_multiset<ll> ims;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        ims.insert(v[i]);
    }
    for (i = 1; i <= q; i++)
    {
        char ch;
        cin >> ch >> a >> b;
        if (ch == '!')
        {
            ims.erase(ims.upper_bound(v[a]));
            v[a] = b;
            ims.insert(v[a]);
        }
        else
        {
            ll ans = ims.order_of_key(b + 1) - ims.order_of_key(a);
            cout << ans << endl;
        }
    }
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