#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define line '\n'
#define gap ' '
typedef long long ll;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p, q;
    // solve stars
    cin >> n >> q;
    vector<ll> stair_dif(n);
    for (auto &x : stair_dif)
    {
        cin >> x;
    }
    vector<ll> quaries(q);
    for (auto &x : quaries)
    {
        cin >> x;
    }
    ll current_max = stair_dif[0];
    multimap<ll, ll> store_with_index;
    for (i = 0; i < n; i++)
    {
        if (stair_dif[i] >= current_max)
        {
            store_with_index.insert({stair_dif[i], i});
            current_max = stair_dif[i];
        }
    }
    vector<ll> pre_sum;
    ll sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + stair_dif[i];
        pre_sum.push_back(sum);
    }
    for (i = 0; i < q; i++)
    {
        auto it = store_with_index.upper_bound(quaries[i]);
        if (it == store_with_index.end())
        {
            cout << pre_sum[n - 1] << gap;
        }
        else
        {
            cout << pre_sum[it->second] - it->first << gap;
        }
    }
    cout << line;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}