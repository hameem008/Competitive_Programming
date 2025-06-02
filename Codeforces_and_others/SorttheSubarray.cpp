#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    ll l = 0, r = n - 1;
    for (i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            break;
        l++;
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            break;
        r--;
    }
    for (i = l; i > 0; i--)
    {
        if (b[i] >= b[i - 1])
            l--;
        else
            break;
    }
    for (i = r; i < n - 1; i++)
    {
        if (b[i] <= b[i + 1])
            r++;
        else
            break;
    }
    cout << l + 1 << gap << r + 1 << endl;
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