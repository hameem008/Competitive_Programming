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
    ll cnt = 0;
    i = 0;
    multiset<ll> ms(v.begin(), v.end());
    for (i = 1; i <= n; i++)
    {
        auto it = ms.lower_bound(i);
        if (it == ms.end())
        {
        }
        else if (*it > i)
        {
            cnt += *it - i;
            ms.erase(it);
            ms.insert(i);
        }
    }
    // for (auto &x : v)
    //     cout << x << gap;
    // cout << endl;
    cout << cnt << endl;
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