#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

bool pf(ll mid, vector<ll> &fruit, vector<ll> &height, vector<pair<ll, ll>> &vp, ll k, vector<ll> &presum)
{
    bool flag = false;
    for (auto x : vp)
    {
        if (x.second - x.first + 1 >= mid)
        {
            ll start = x.first, end = x.first + mid - 1;
            while (end <= x.second)
            {
                if (presum[end] - presum[start - 1] <= k)
                    flag = true;
                start++, end++;
            }
        }
    }
    return flag;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> height(n + 1, 0), fruit(n + 1, 0), presum(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> fruit[i];
    for (i = 1; i <= n; i++)
        cin >> height[i];
    for (i = 1; i <= n; i++)
    {
        presum[i] = fruit[i] + presum[i - 1];
    }
    vector<pair<ll, ll>> vp;
    ll start = 1, end = 1;
    for (i = 1; i < n; i++)
    {
        if (height[i] % height[i + 1] == 0)
        {
            end++;
        }
        else
        {
            if (end - start > 0)
                vp.push_back({start, end});
            start = end = i + 1;
        }
    }
    if (end - start > 0)
        vp.push_back({start, end});
    if (vp.size() == 0)
    {
        for (i = 1; i <= n; i++)
        {
            if (fruit[i] <= k)
            {
                cout << 1 << endl;
                return;
            }
        }
        cout << 0 << endl;
    }
    else
    {
        flag = false;
        for (i = 1; i <= n; i++)
        {
            if (fruit[i] <= k)
                flag = true;
        }
        if (!flag)
        {
            cout << 0 << endl;
            return;
        }
        ll hi = n, lo = 1, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (pf(mid, fruit, height, vp, k, presum))
                lo = mid;
            else
                hi = mid - 1;
        }
        if (pf(hi, fruit, height, vp, k, presum))
            cout << hi << endl;
        else
            cout << lo << endl;
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