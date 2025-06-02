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
    vector<ll> v(n + 1), prefix(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    ll sum = 0;
    for (i = 1; i <= n; i++)
    {
        sum += v[i];
        prefix[i] = sum;
    }
    ll ans = 0;
    ll var = prefix[m];
    multiset<ll> ms;
    ms.insert(v[m]);
    for (i = m - 1; i >= 1; i--)
    {
        if (var > prefix[i])
        {
            ans++;
            var -= *(--ms.end()) * 2;
            ms.erase(--ms.end());
        }
        ms.insert(v[i]);
    }
    ms.clear();
    var = prefix[m];
    ll cursum = prefix[m];
    for (i = m + 1; i <= n; i++)
    {
        cursum += v[i];
        ms.insert(v[i]);
        if (cursum < var)
        {
            ans++;
            cursum -= *(ms.begin()) * 2;
            ms.erase(ms.begin());
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