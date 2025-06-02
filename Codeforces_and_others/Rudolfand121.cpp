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
    bool flag = true;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    for (i = 1; i < n - 1; i++)
    {
        if (v[i - 1] > 0)
        {
            v[i] -= 2 * v[i - 1];
            v[i + 1] -= v[i - 1];
            v[i - 1] -= v[i - 1];
        }
        else if (v[i - 1] < 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (auto x : v)
    {
        if (x != 0)
            flag = false;
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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