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
    cin >> n >> m;
    map<ll, ll> mp;
    mp[-i] = 0;
    mp[-2] = 0;
    set<ll> s;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        if (a < 0)
            mp[a]++;
        else
            s.insert(a);
    }
    vector<ll> v(s.begin(), s.end());
    if (mp[-1] >= m || mp[-2] >= m)
    {
        cout << m << endl;
        return;
    }
    ll ans = 0;
    ans = min((ll)(mp[-1] + v.size()), m);
    ans = max(ans, min((ll)(mp[-2] + v.size()), m));
    for (i = 0; i < v.size(); i++)
    {
        ll temp_ans = 1;
        temp_ans += min((ll)(mp[-2] + v.size() - i - 1), m - v[i]);
        temp_ans += min(mp[-1] + i, v[i] - 1);
        ans = max(temp_ans, ans);
    }
    ans = max(max(min(m, mp[-1]), min(m, mp[-2])), ans);
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