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
    cin >> n;
    set<ll> s;
    vector<pair<ll, ll>> vp;
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b;
        s.insert(a);
        s.insert(b);
        vp.push_back({a, b});
    }
    unordered_map<ll, ll> time_to_index;
    i = 1;
    for (auto x : s)
    {
        time_to_index[x] = i;
        i++;
    }
    vector<ll> pre_start(i + 8, 0), pre_end(i + 8, 0);
    for (auto x : vp)
    {
        pre_start[time_to_index[x.first]]++;
        pre_end[time_to_index[x.second]]++;
    }
    for (i = 1; i < pre_start.size(); i++)
    {
        pre_start[i] += pre_start[i - 1];
    }
    for (i = 1; i < pre_end.size(); i++)
    {
        pre_end[i] += pre_end[i - 1];
    }
    ll ans = 0;
    for (auto x : vp)
    {
        ll point = x.first;
        ll dum_ans = n - (pre_end[time_to_index[point] - 1]) - (pre_start[pre_start.size() - 1] - pre_start[time_to_index[point]]);
        ans = max(ans, dum_ans);
        point = x.second;
        dum_ans = n - (pre_end[time_to_index[point] - 1]) - (pre_start[pre_start.size() - 1] - pre_start[time_to_index[point]]);
        ans = max(ans, dum_ans);
    }
    cout << ans << endl;
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