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
    multiset<ll> ms;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        ms.insert(a);
    }
    vector<ll> v(m + 1, 0);
    for (i = 1; i <= m; i++)
    {
        cin >> v[i];
    }
    vector<ll> ans(m + 1, -1);
    for (i = 1; i <= m; i++)
    {
        if (ms.size() == 0)
            break;
        auto it = ms.upper_bound(v[i]);
        if (it != ms.begin())
        {
            it--;
            ans[i] = *it;
            ms.erase(it);
        }
    }
    for (i = 1; i <= m; i++)
    {
        cout << ans[i] << endl;
    }
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