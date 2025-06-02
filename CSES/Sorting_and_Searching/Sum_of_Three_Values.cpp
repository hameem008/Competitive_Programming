#include <bits/stdc++.h>
#include <time.h>
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
    cin >> n >> k;
    vector<ll> v(n);
    set<ll> s;
    for (auto &x : v)
    {
        cin >> x;
        s.insert(k - x);
    }
    map<ll, pair<ll, ll>> mp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            pair<ll, ll> pr = {0, 0};
            auto it = s.find(v[i] + v[j]);
            if (it != s.end() && mp[v[i] + v[j]] == pr)
                mp[v[i] + v[j]] = {i, j};
        }
    }
    for (i = 0; i < n; i++)
    {
        pair<ll, ll> x = mp[k - v[i]];
        pair<ll, ll> pr = {0, 0};
        if (x != pr && x.first != i && x.second != i)
        {
            cout << i + 1 << gap << x.first + 1 << gap << x.second + 1 << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
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