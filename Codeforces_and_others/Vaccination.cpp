#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, w, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k >> d >> w;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll ans = 0, dose = 0, endtime, begtime;
    bool pack = false;
    for (i = n - 1; i >= 0; i--)
    {
        if (!pack)
        {
            ans++;
            endtime = v[i];
            begtime = v[i];
            dose++;
            pack = true;
        }
        else
        {
            if (v[i] + w < endtime)
                begtime = v[i] + w;
            dose++;
            if (dose > k || endtime - begtime > d)
            {
                i++;
                pack = false;
                dose = 0;
            }
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}