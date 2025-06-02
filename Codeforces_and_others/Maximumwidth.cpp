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
    string s, t;
    cin >> s >> t;
    vector<ll> dp_front(m, 0), dp_back(m, 0);
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (j == m)
            break;
        if (t[j] == s[i])
        {
            dp_front[j] = i;
            j++;
        }
    }
    j = m - 1;
    for (i = n - 1; i >= 0; i--)
    {
        if (j < 0)
            break;
        if (t[j] == s[i])
        {
            dp_back[j] = i;
            j--;
        }
    }
    ll ans = -infinite;
    for (i = 0; i < m - 1; i++)
    {
        ans = max(ans, dp_back[i + 1] - dp_front[i]);
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