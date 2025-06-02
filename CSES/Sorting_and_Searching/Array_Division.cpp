#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool pf(ll mid, vector<ll> &v, ll k)
{
    ll sub_cnt = 1;
    ll sum = 0;
    for (auto x : v)
    {
        sum += x;
        if (sum > mid)
        {
            sub_cnt++;
            sum = x;
        }
    }
    if (sub_cnt <= k)
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
    ll hi = accumulate(v.begin(), v.end(), 0LL), lo = *max_element(v.begin(), v.end()), mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, v, k))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (pf(lo, v, k))
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}