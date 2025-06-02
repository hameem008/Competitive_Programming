#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

bool pf(ll mid, vector<vector<ll>> &v, ll m, ll n)
{
    vector<ll> cnt(m, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] >= mid)
                cnt[i]++;
        }
    }
    ll max_ele = *max_element(cnt.begin(), cnt.end());
    if (max_ele > 1)
        return true;
    else
        return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> m >> n;
    vector<vector<ll>> v(m, vector<ll>(n, 0));
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    ll min_max = infinite;
    for (i = 0; i < n; i++)
    {
        ll curr_max = 0;
        for (j = 0; j < m; j++)
        {
            curr_max = max(curr_max, v[j][i]);
        }
        min_max = min(curr_max, min_max);
    }
    ll hi = min_max, lo = 1, mid;
    while (hi - lo > 1) 
    {
        mid = (hi + lo) / 2;
        if (pf(mid, v, m, n))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf(hi, v, m, n))
        cout << hi << endl;
    else
        cout << lo << endl;
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