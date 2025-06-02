#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll fun(ll mid, vector<ll> v, ll k)
{
    ll ret = 0;
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    sum = sum - v[0] + mid;
    ret = v[0] - mid;
    while (v.size() > 1)
    {
        if (sum <= k)
            break;
        if (v.back() != mid)
            ret++;
        sum = sum - v.back() + mid;
        v.pop_back();
    }
    if (sum > k)
        ret = infinite;
    return ret;
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
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    sort(v.begin(), v.end());
    ll lo = -sum, hi = v.front();
    while (1)
    {
        if (hi > 0 && lo > 0)
        {
            if (hi - lo <= 10)
                break;
        }
        else if (hi < 0 && lo < 0)
        {
            if (abs(abs(hi) - abs(lo)) <= 10)
                break;
        }
        else
        {
            if (hi - lo <= 10)
                break;
        }
        ll mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
        ll ans1 = fun(mid1, v, k), ans2 = fun(mid2, v, k);
        if (ans1 < ans2)
            hi = mid2;
        else if (ans1 > ans2)
            lo = mid1;
        else
        {
            hi = mid2;
            lo = mid1;
        }
        i++;
    }
    ll ans = max(sum - k, 0LL);
    for (i = lo; i <= hi; i++)
    {
        ans = min(ans, fun(i, v, k));
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