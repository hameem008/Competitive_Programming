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
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll limit = 2 * k;
    sort(v.begin(), v.end());
    i = n - 1;
    vector<ll> deletev(2e5 + 1, 0);
    while (limit--)
    {
        deletev[v[i]]++;
        i--;
    }
    ll maxfnum;
    ll maxf = 0;
    for (i = 0; i < deletev.size(); i++)
    {
        if (maxf < deletev[i])
        {
            maxf = deletev[i];
            maxfnum = i;
        }
    }
    ll ans = 0;
    if (maxf > k)
    {
        ans += (2 * maxf - 2 * k) / 2;
    }
    for (i = 0; i < n - 2 * k; i++)
    {
        ans += v[i];
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