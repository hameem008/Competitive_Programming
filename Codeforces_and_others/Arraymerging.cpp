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
    vector<ll> va(n), vb(n);
    for (auto &x : va)
        cin >> x;
    for (auto &x : vb)
        cin >> x;
    vector<ll> cnt_a(2 * n + 1, 0), cnt_b(2 * n + 1, 0);
    ll cur_num = va.front(), cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (cur_num == va[i])
        {
            cnt++;
        }
        else
        {
            cnt_a[cur_num] = max(cnt_a[cur_num], cnt);
            cnt = 1;
            cur_num = va[i];
        }
    }
    cnt_a[cur_num] = max(cnt_a[cur_num], cnt);

    cur_num = vb.front(), cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (cur_num == vb[i])
        {
            cnt++;
        }
        else
        {
            cnt_b[cur_num] = max(cnt_b[cur_num], cnt);
            cnt = 1;
            cur_num = vb[i];
        }
    }
    cnt_b[cur_num] = max(cnt_b[cur_num], cnt);

    ll ans = 0;
    for (i = 0; i < 2 * n + 1; i++)
    {
        ans = max(ans, cnt_a[i] + cnt_b[i]);
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