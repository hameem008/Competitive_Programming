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
    multiset<ll> ms;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        ms.insert(a);
    }
    ll ans = 0;
    while (ms.size())
    {
        ans++;
        auto it = ms.end();
        it--;
        ll rem = k - *it;
        ms.erase(it);
        auto it2 = ms.lower_bound(rem);
        if (it2 != ms.end())
        {
            if (*it2 == rem)
            {
                ms.erase(it2);
            }
            else if (it2 != ms.begin())
            {
                it2--;
                ms.erase(it2);
            }
        }
        else
        {
            if (it2 != ms.begin())
            {
                it2--;
                ms.erase(it2);
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}