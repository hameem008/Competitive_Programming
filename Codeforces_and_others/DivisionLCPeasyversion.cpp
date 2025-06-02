#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> z_function(string s)
{
    ll n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        { 
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    ll l, r;
    cin >> n >> l >> r;
    cin >> str;
    vector<ll> ans(n + 1, 0);
    ans[1] = n;
    ll done = 1;
    vector<ll> pi = z_function(str);
    vector<set<ll>> vs(n + 1);
    for (i = 0; i < n; i++)
    {
        vs[pi[i]].insert(i);
    }
    set<ll> ind;
    ind.insert(0);
    for (i = n; i >= 1; i--)
    {
        for (auto x : vs[i])
            ind.insert(x);
        ll cnt = 0;
        auto it = ind.begin();
        while (it != ind.end())
        {
            cnt++;
            it = ind.lower_bound(*it + i);
        }
        while (done <= cnt)
        {
            ans[done] = max(ans[done], i);
            done++;
        }
    }
    for (i = l; i <= r; i++)
        cout << ans[i] << gap;
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