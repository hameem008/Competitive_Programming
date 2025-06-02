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
    vector<ll> cnt(31, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        for (ll mask = 0; mask <= 30; mask++)
        {
            if ((a & (1 << mask)))
            {
                cnt[mask]++;
            }
        }
    }
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        ll num = 0;
        for (j = 0; j <= 30; j++)
        {
            if (cnt[j] > 0)
            {
                num |= (1 << j);
                cnt[j]--;
            }
        }
        ans += num * num;
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