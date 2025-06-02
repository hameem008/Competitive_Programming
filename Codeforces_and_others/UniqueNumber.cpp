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
    cin >> k;
    vector<ll> v;
    for (i = 9; i >= 1; i--)
    {
        if (k - i >= 0)
        {
            v.push_back(i);
            k -= i;
        }
    }
    if (k == 0)
    {
        reverse(v.begin(), v.end());
        for (auto &x : v)
            cout << x;
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
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