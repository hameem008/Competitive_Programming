#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll manDist(pair<ll, ll> a, pair<ll, ll> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool isPos(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    return manDist(a, c) == manDist(a, b) + manDist(b, c);
}

void solve(int I, int T)
{
    ll i, j, k, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    set<pair<ll, ll>> ans;
    if (n == 3)
    {
        i = 1;
        pair<ll, ll> a = {v[i], i}, b = {v[i + 1], i + 1}, c = {v[i + 2], i + 2};
        if (!isPos(a, b, c))
            ans.insert({i, i + 2});
    }
    else if (n >= 3)
    {
        for (i = 1; i <= n - 3; i++)
        {
            pair<ll, ll> a = {v[i], i}, b = {v[i + 1], i + 1}, c = {v[i + 2], i + 2}, d = {v[i + 3], i + 3};
            if (!isPos(a, b, c))
                ans.insert({i, i + 2});
            if (!isPos(b, c, d))
                ans.insert({i + 1, i + 3});
            if (!isPos(a, b, c) && !isPos(a, b, d) && !isPos(a, c, d) && !isPos(b, c, d))
                ans.insert({i, i + 3});
        }
    }
    cout << ans.size() + 2 * n - 1 << endl;
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