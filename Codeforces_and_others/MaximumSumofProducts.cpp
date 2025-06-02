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
    vector<ll> va(n + 1), vb(n + 1);
    for (i = 1; i <= n; i++)
        cin >> va[i];
    for (i = 1; i <= n; i++)
        cin >> vb[i];
    vector<ll> presum_front(n + 1, 0), presum_back(n + 2, 0);
    for (i = 1; i <= n; i++)
    {
        presum_front[i] += presum_front[i - 1] + va[i] * vb[i];
    }
    for (i = n; i >= 1; i--)
    {
        presum_back[i] += presum_back[i + 1] + va[i] * vb[i];
    }
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        ll start = i, end = i, mul = 0;
        while (1)
        {
            if (start < 1 || end > n)
                break;
            mul += va[start] * vb[end] + va[end] * vb[start];
            if (start == end)
                mul -= va[end] * vb[start];
            ans = max(ans, presum_front[start - 1] + mul + presum_back[end + 1]);
            start--, end++;
        }
    }
    for (i = 1; i <= n; i++)
    {
        ll start = i, end = i + 1, mul = 0;
        while (1)
        {
            if (start < 1 || end > n)
                break;
            mul += va[start] * vb[end] + va[end] * vb[start];
            ans = max(ans, presum_front[start - 1] + mul + presum_back[end + 1]);
            start--, end++;
        }
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