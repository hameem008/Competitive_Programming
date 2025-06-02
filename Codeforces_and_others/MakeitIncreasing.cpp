#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

ll check(vector<ll> v, ll indZero, ll n)
{
    ll ans = 0;
    vector<ll> ch(v.begin(), v.end());
    int i;
    v[indZero] = 0;
    for (i = indZero; i > 0; i--)
    {
        if (v[i] >= v[i - 1])
        {
            v[i - 1] = (v[i] / v[i - 1] + 1) * v[i - 1];
        }
    }
    for (i = indZero; i < n - 1; i++)
    {
        if (v[i] >= v[i + 1])
        {
            v[i + 1] = (v[i] / v[i + 1] + 1) * v[i + 1];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i != indZero)
        {
            ans += v[i] / ch[i];
        }
    }
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll ans = LONG_LONG_MAX;
    for (i = 0; i < n; i++)
    {
        ll temp = check(v, i, n);
        if (ans > temp)
            ans = temp;
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