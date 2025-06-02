#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef int ll;
typedef long double lld;
const ll N = 5002;

ll bn_ind[N][N];
ll cn_ind[N][N];

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    vector<ll> pos(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        pos[v[i]] = i;
    }
    for (ll cn = 1; cn <= n; cn++)
    {
        ll cnt = 0;
        for (i = 1; i <= pos[cn]; i++)
        {
            if (v[i] < cn)
                cnt++;
            cn_ind[cn][i] = cnt;
        }
    }
    for (ll bn = 1; bn <= n; bn++)
    {
        ll cnt = 0;
        for (i = n; i >= pos[bn]; i--)
        {
            if (v[i] < bn)
                cnt++;
            bn_ind[bn][i] = cnt;
        }
    }
    long long ans = 0;
    for (ll b_ind = 1; b_ind <= n; b_ind++)
    {
        for (ll c_ind = b_ind + 1; c_ind <= n; c_ind++)
        {
            ans += (long long)bn_ind[v[b_ind]][c_ind + 1] * (long long)cn_ind[v[c_ind]][b_ind - 1];
        }
    }
    cout << ans << endl;
    for (ll cn = 1; cn <= n; cn++)
    {
        ll cnt = 0;
        for (i = 1; i <= pos[cn]; i++)
        {
            cn_ind[cn][i] = cnt;
        }
    }
    for (ll bn = 1; bn <= n; bn++)
    {
        ll cnt = 0;
        for (i = n; i >= pos[bn]; i--)
        {
            bn_ind[bn][i] = cnt;
        }
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