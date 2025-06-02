#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> v;
vector<pair<ll, ll>> ans;
void fun(ll a, ll b)
{
    while (v[a] != v[b])
    {
        if (v[a] / v[b] >= 1)
        {
            v[a] % v[b] == 0 ? v[a] /= v[b] : v[a] = v[a] / v[b] + 1;
            ans.push_back({a, b});
        }
        else
        {
            v[b] % v[a] == 0 ? v[b] /= v[a] : v[b] = v[b] / v[a] + 1;
            ans.push_back({b, a});
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    ans.clear();
    v.clear();
    v.assign(n, 0);
    for (auto &x : v)
        cin >> x;
    set<ll> s(v.begin(), v.end());
    if (s.size() == 1)
    {
        cout << 0 << endl;
        return;
    }
    for (auto x : v)
    {
        if (x == 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            fun(i, j);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x.first + 1 << gap << x.second + 1 << endl;
    }
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