#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll one_cnt = 0;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
            one_cnt++;
    }
    ll ans = 0;
    if (one_cnt % 2 == 0)
    {
        ans = one_cnt / 2 + (v.size() - one_cnt);
    }
    else
    {
        one_cnt--;
        ans = one_cnt / 2 + (v.size() - one_cnt);
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