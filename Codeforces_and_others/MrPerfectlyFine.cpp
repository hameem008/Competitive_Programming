#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    map<string, ll> mp;
    mp.insert({"01", infinite});
    mp.insert({"10", infinite});
    mp.insert({"11", infinite});
    cin >> n;
    for (i = 0; i < n; i++)
    {
        string str;
        cin >> m >> str;
        if (str != "00")
        {
            mp[str] = min(mp[str], m);
        }
    }
    ll ans = min(mp["01"] + mp["10"], mp["11"]);
    if (ans == infinite)
        cout << -1 << endl;
    else
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