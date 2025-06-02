#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m;
    vector<ll> conflict(n + 1, 0);
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (b > a)
        {
            if (conflict[b] < a)
                conflict[b] = a;
        }
        if (b < a)
        {
            if (conflict[a] < b)
                conflict[a] = b;
        }
    }
    set<ll> curr_con;
    ll ans = 0;
    ll start = 1, end = 1;
    for (i = 1; i <= n; i++)
    {
        if (start <= conflict[i])
        {
            a = end - start;
            ans += a * (a + 1) / 2;
            start = conflict[i] + 1;
            a = end - start;
            ans -= a * (a + 1) / 2;
            end++;
        }
        else
        {
            end++;
        }
    }
    a = end - start;
    ans += a * (a + 1) / 2;
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}