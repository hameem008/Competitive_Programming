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
    ll sign;
    if (v[0] < 0)
        sign = 0;
    else
        sign = 1;
    ll ans = 0;
    ll curr_max = v[0];
    for (i = 0; i < n; i++)
    {
        if (v[i] < 0 && sign == 0)
        {
            curr_max = max(curr_max, v[i]);
        }
        else if (v[i] > 0 && sign == 1)
        {
            curr_max = max(curr_max, v[i]);
        }
        else
        {
            sign ? sign = 0 : sign = 1;
            ans += curr_max;
            curr_max = v[i];
        }
    }
    ans += curr_max;
    cout << ans << endl;
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