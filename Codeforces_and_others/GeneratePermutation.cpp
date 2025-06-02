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
    cin >> n;
    if (n % 2 == 0)
        cout << -1 << endl;
    else
    {
        vector<ll> v;
        for (i = 2; i < n; i += 2)
        {
            v.push_back(i);
        }
        for (i = n; i > 0; i -= 2)
        {
            v.push_back(i);
        }
        for (auto x : v)
            cout << x << gap;
        cout << endl;
    }
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