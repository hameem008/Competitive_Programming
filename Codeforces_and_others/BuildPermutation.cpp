#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

set<ll> square;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> ans(n, 0);
    n--;
    ll last_square;
    m = n;
    while (accumulate(ans.begin(), ans.end(), 0LL) != n * (n + 1) / 2)
    {
        last_square = *square.lower_bound(m);
        for (i = last_square - m, j = m; i <= m; i++, j--)
        {
            ans[i] = j;
        }
        m = j;
    }
    for (auto x : ans)
        cout << x << gap;
    cout << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 1e5 + 1; i++)
    {
        square.insert(i * i);
    }
    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}