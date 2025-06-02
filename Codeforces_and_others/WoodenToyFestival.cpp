#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool pf(ll ans, vector<ll> &v)
{
    ll upper, i = 0, cnt = 0;
    upper = v[i] + 2 * ans;
    for (; i < v.size(); i++)
    {
        if (v[i] <= upper)
            cnt++;
        else
            break;
    }
    if (i == v.size())
        return true;
    upper = v[i] + 2 * ans;
    for (; i < v.size(); i++)
    {
        if (v[i] <= upper)
            cnt++;
        else
            break;
    }
    if (i == v.size())
        return true;
    upper = v[i] + 2 * ans;
    for (; i < v.size(); i++)
    {
        if (v[i] <= upper)
            cnt++;
        else
            break;
    }
    return cnt == v.size();
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll hi = 1e9 + 1, lo = 0, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, v))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (pf(lo, v))
        cout << lo << endl;
    else
        cout << hi << endl;
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