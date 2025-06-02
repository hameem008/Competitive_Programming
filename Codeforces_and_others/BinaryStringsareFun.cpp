#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
ll MOD = 998244353;

ll binExp(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll rec = binExp(a, b / 2, mod);
    if (b % 2 != 0)
        return ((a % mod) * (rec % mod) % mod) * (rec % mod) % mod;
    else
        return (rec % mod) * (rec % mod) % mod;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<char> str(n + 1);
    for (i = 1; i <= n; i++)
        cin >> str[i];
    ll ans = 0, one_cnt = 0, zero_cnt = 0, blank_cnt = -1;
    for (i = 1; i <= n; i++)
    {
        blank_cnt++;
        if (str[i] == '1')
        {
            one_cnt++;
            if (one_cnt < i)
            {
                blank_cnt -= (i - one_cnt);
                one_cnt = i;
            }
        }
        else
        {
            zero_cnt++;
            if (zero_cnt < i)
            {
                blank_cnt -= (i - zero_cnt);
                zero_cnt = i;
            }
        }
        ans += binExp(2, blank_cnt, MOD);
        ans %= MOD;
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