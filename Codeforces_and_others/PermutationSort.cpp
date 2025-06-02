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
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    flag = true;
    for (i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
            flag = false;
    }
    if (flag)
    {
        cout << 0 << endl;
        return;
    }
    if (v[0] == 1 || v[n - 1] == n)
    {
        cout << 1 << endl;
    }
    else if (v[0] == n && v[n - 1] == 1)
    {
        cout << 3 << endl;
    }
    else
    {
        cout << 2 << endl;
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