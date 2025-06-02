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
    vector<ll> v(n * m);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll maxi1 = v[n * m - 1], maxi2 = v[n * m - 2];
    ll mini1 = v[0], mini2 = v[1];
    if (n > m)
    {
        ll ans1 = 0, ans2 = 0;
        ans1 += (n - 1) * (maxi1 - mini1);
        ans1 += (m - 1) * (maxi1 - mini2);
        ans1 += (n - 1) * (m - 1) * (maxi1 - mini1);

        ans2 += (n - 1) * (maxi1 - mini1);
        ans2 += (m - 1) * (maxi2 - mini1);
        ans2 += (n - 1) * (m - 1) * (maxi1 - mini1);

        cout << max(ans1, ans2) << endl;
    }
    else if (n < m)
    {
        ll ans1 = 0, ans2 = 0;
        ans1 += (m - 1) * (maxi1 - mini1);
        ans1 += (n - 1) * (maxi1 - mini2);
        ans1 += (n - 1) * (m - 1) * (maxi1 - mini1);

        ans2 += (m - 1) * (maxi1 - mini1);
        ans2 += (n - 1) * (maxi2 - mini1);
        ans2 += (n - 1) * (m - 1) * (maxi1 - mini1);

        cout << max(ans1, ans2) << endl;
    }
    else
    {
        ll ans1 = 0, ans2 = 0;
        ans1 += (m - 1) * (maxi1 - mini1);
        ans1 += (n - 1) * (maxi1 - mini2);
        ans1 += (n - 1) * (m - 1) * (maxi1 - mini1);

        ans2 += (m - 1) * (maxi1 - mini1);
        ans2 += (n - 1) * (maxi2 - mini1);
        ans2 += (n - 1) * (m - 1) * (maxi1 - mini1);

        cout << max(ans1, ans2) << endl;
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