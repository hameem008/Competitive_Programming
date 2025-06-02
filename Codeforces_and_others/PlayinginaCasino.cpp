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
    vector<ll> dum(m);
    vector<vector<ll>> v(n, dum);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cin >> v[i][j];
    }
    for (j = 0; j < m; j++)
    {
        vector<ll> vs;
        for (i = 0; i < n; i++)
        {
            vs.push_back(v[i][j]);
        }
        sort(vs.begin(), vs.end());
        for (i = 0; i < n; i++)
        {
            v[i][j] = vs[i];
        }
    }
    vector<ll> vsum;
    for (i = 0; i < n; i++)
    {
        ll sum = 0;
        for (j = 0; j < m; j++)
        {
            sum += v[i][j];
        }
        vsum.push_back(sum);
    }
    ll ans = 0;
    sort(vsum.begin(), vsum.end());
    reverse(vsum.begin(), vsum.end());
    ll sum = 0;
    for (auto x : vsum)
        sum += x;
    ll mul = vsum.size() - 1;
    for (i = 0; i < vsum.size(); i++)
    {
        ans += mul * vsum[i] - (sum - vsum[i]);
        mul--;
        sum -= vsum[i];
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}