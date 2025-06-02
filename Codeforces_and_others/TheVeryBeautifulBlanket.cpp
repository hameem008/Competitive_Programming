#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

set<ll> twoPower;

void solve(int I, int T)
{
    ll i, j, k, a = 0, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    ll pow2 = *twoPower.lower_bound(m);
    a = (pow2 - m) % 2 == 0 ? (pow2 - m) / 2 : (pow2 - m) / 2 + 1;
    vector<ll> vo(m, 0);
    vector<vector<ll>> v(n, vo);
    ll curr = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            v[i][j] = curr;
            curr += 2;
        }
        curr = (curr / 4 + a) * 4 + 1;
    }
    cout << n * m << endl;
    for (auto x : v)
    {
        for (auto y : x)
            cout << y << gap;
        cout << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 32; i++)
        twoPower.insert(pow(2, i));
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}