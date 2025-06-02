#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, f, m, n, p, q;
    bool flag = true;
    // solve starts
    cin >> n >> f >> a >> b;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    for (i = n - 1; i > 0; i--)
    {
        v[i] = v[i] - v[i - 1];
    }
    ll ans = 0;
    for (auto x : v)
    {
        if (flag)
        {
            if (x * a < b)
            {
                ans += x * a;
            }
            else
            {
                ans += b;
                flag = false;
            }
        }
        else
        {
            flag = true;
            ans += b;
        }
    }
    if (ans >= f)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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