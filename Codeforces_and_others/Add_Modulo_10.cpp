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
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    set<ll> s;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        if (p % 10 == 5)
            p = p + 5;
        s.insert(p);
    }
    if (s.size() == 1)
    {
        cout << "Yes" << line;
        return;
    }
    set<ll> set1 = {1, 2, 4, 8, 13, 16, 17, 19};
    set<ll> set2 = {3, 6, 7, 9, 11, 12, 14, 18};
    set<ll> ans;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        ans.insert(*it % 20);
    }
    ll size_set1 = set1.size();
    ll size_set2 = set2.size();
    for (auto x : ans)
    {
        set1.insert(x);
    }
    if (set1.size() == size_set1)
    {
        cout << "Yes" << line;
        return;
    }
    for (auto x : ans)
    {
        set2.insert(x);
    }
    if (set2.size() == size_set2)
    {
        cout << "Yes" << line;
        return;
    }
    cout << "No" << line;
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