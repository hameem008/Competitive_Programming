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
    cin >> a >> b >> c;
    vector<ll> ans(3, 0);
    if (abs(a - b) % 2 == 0)
    {
        ans[2] = 1;
    }
    if (abs(c - a) % 2 == 0)
    {
        ans[1] = 1;
    }
    if (abs(b - c) % 2 == 0)
    {
        ans[0] = 1;
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

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}