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
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    set<pair<ll, ll>> s;
    set<ll> stest;
    for (i = n - 1; i >= 0; i--)
    {
        ll size = stest.size();
        stest.insert(v[i]);
        if (size != stest.size())
        {
            s.insert({v[i], i});
        }
    }
    vector<pair<ll, ll>> ans;
    vector<ll> min_test;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        min_test.push_back(it->first);
        ans.push_back(*it);
    }
    ll min_gcd_test = min_test[0];
    for (i = 0; i < min_test.size(); i++)
    {
        min_gcd_test = __gcd(min_gcd_test, min_test[i]);
    }
    set<ll> answer;
    ll gcd = 0;
    for (i = 0; i < ans.size(); i++)
    {
        for (j = 0; j < ans.size(); j++)
        {
            gcd = __gcd(ans[i].first, ans[j].first);
            if (gcd == 1)
            {
                answer.insert(ans[i].second + ans[j].second);
            }
        }
    }
    if (answer.size() == 0)
    {
        cout << -1 << line;
        return;
    }
    auto IT = answer.end();
    IT--;
    cout << *IT + 2 << line;
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