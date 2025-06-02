#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll fun(vector<ll> &v)
{
    ll max_ele = 0, ans = 0;
    for (int i = 1; i < v.size(); i++)
    {
        ans += i * v[i];
        max_ele = max(i * v[i], max_ele);
    }
    return ans - max_ele;
}
void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        v[i] = i;
    ll ans = 0;
    for (i = 0; i <= n; i++)
    {
        vector<ll> dum = v;
        reverse(dum.end() - i, dum.end());
        ans = max(ans, fun(dum));
    }
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