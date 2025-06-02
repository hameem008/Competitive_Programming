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
    ll cnt1 = 0, cnt2 = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == v.front())
            cnt1++;
        else
            break;
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (v[i] == v.back())
            cnt2++;
        else
            break;
    }
    if (v.front() == v.back())
    {
        cout << max(0LL, n - cnt1 - cnt2) << endl;
    }
    else
    {
        cout << min(n - cnt1, n - cnt2) << endl;
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