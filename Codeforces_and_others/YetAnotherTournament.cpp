#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    ll dm = m;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> dum(v.begin(), v.end());
    sort(dum.begin(), dum.end());
    ll winm = 0;
    for (auto x : dum)
    {
        dm -= x;
        if (dm >= 0)
            winm++;
    }
    if (winm == 0 || winm == n)
    {
        if (winm == 0)
            cout << n + 1 << endl;
        else
            cout << 1 << endl;
        return;
    }
    ll dmwinm = 0;
    dm = m - v[winm];
    if (dm >= 0)
        dmwinm++;
    dum.erase(find(dum.begin(), dum.end(), v[winm]));
    for (auto x : dum)
    {
        dm -= x;
        if (dm >= 0)
            dmwinm++;
    }
    if (dmwinm == winm)
    {
        cout << n - winm << endl;
    }
    else
    {
        cout << n - winm + 1 << endl;
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