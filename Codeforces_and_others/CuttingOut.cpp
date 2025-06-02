#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> ans;
bool pf(ll mid, ll k, vector<ll> &v)
{
    ans.clear();
    vector<ll> fr(2e5 + 1, 0);
    for (auto x : v)
    {
        fr[x]++;
        if (fr[x] == mid)
        {
            fr[x] = 0;
            ans.push_back(x);
        }
    }
    if (ans.size() >= k)
        return true;
    else
        return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll hi = n, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, k, v))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf(hi, k, v))
    {
        sort(ans.begin(), ans.end());
        for (i = 0; i < k; i++)
        {
            cout << ans[i] << gap;
        }
        cout << endl;
    }
    else if (pf(lo, k, v))
    {
        sort(ans.begin(), ans.end());
        for (i = 0; i < k; i++)
        {
            cout << ans[i] << gap;
        }
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}