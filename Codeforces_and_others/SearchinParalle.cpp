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
    ll search_time_1, search_time_2;
    cin >> n >> search_time_1 >> search_time_2;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    multimap<ll, ll> mp;
    for (i = 1; i <= n; i++)
    {
        mp.insert({v[i], i});
    }
    ll curr_time_1 = search_time_1, curr_time_2 = search_time_2;
    vector<ll> ans1, ans2;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        if (curr_time_1 > curr_time_2)
        {
            ans2.push_back(it->second);
            curr_time_2 += search_time_2;
        }
        else if (curr_time_1 < curr_time_2)
        {
            ans1.push_back(it->second);
            curr_time_1 += search_time_1;
        }
        else if (search_time_1 > search_time_2)
        {
            ans2.push_back(it->second);
            curr_time_2 += search_time_2;
        }
        else if (search_time_1 < search_time_2)
        {
            ans1.push_back(it->second);
            curr_time_1 += search_time_1;
        }
        else
        {
            ans1.push_back(it->second);
            curr_time_1 += search_time_1;
        }
    }
    cout << ans1.size() << gap;
    for (auto x : ans1)
        cout << x << gap;
    cout << endl;
    cout << ans2.size() << gap;
    for (auto x : ans2)
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