#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, x, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> x;
    multiset<ll> ms;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        ms.insert(a);
    }
    ll ans = 0;
    while (ms.size())
    {
        auto it = ms.find(*ms.begin() * x);
        if (it != ms.end())
        {
            ms.erase(it);
            ms.erase(ms.begin());
        }
        else
        {
            ms.erase(ms.begin());
            ans++;
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