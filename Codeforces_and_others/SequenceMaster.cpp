#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll fun(vector<ll> &v)
{
    ll n = v.size() / 2;
    ll ind = lower_bound(v.begin(), v.end(), n) - v.begin();
    if (ind >= 2 * n)
    {
        ind = 2 * n - 1;
    }
    ll sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i != ind)
            sum += abs(v[i] + 1);
    }
    sum += abs(v[ind] - n);
    return sum;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(2 * n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll sum = 0, ans = INT64_MAX;
    if (n == 1)
    {
        cout << abs(v[0] - v[1]) << endl;
    }
    else if (n == 2)
    {
        sum = 0, ans = INT64_MAX;
        for (auto x : v)
            sum += abs(x);
        ans = min(ans, sum);
        sum = 0;
        for (auto x : v)
            sum += abs(x - 2);
        ans = min(ans, sum);
        sum = 0;
        sum = fun(v);
        ans = min(sum, ans);
        cout << ans << endl;
    }
    else if (n % 2 != 0)
    {
        sum = 0, ans = INT64_MAX;
        for (auto x : v)
            sum += abs(x);
        ans = min(ans, sum);
        cout << ans << endl;
    }
    else
    {
        sum = 0, ans = INT64_MAX;
        for (auto x : v)
            sum += abs(x);
        ans = min(ans, sum);
        sum = fun(v);
        ans = min(ans, sum);
        cout << ans << endl;
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