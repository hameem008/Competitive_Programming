#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll a, b;
ll v[200008];
ll presum[200008];

ll kop(ll n)
{
    ll ans = 1e15;
    for (int i = n - 1; i >= 0; i--)
    {
        ans = min(ans, (presum[n] - presum[i] - v[i] * (n - i - 1)) * b + v[i] * a);
    }
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> a >> b;
    ll sum = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum += v[i];
        presum[i] = sum;
    }
    cout << kop(n) << endl;
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