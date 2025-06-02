#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

bool pff(ll mid, ll cnt_1, ll cnt_2, vector<ll> &point1, vector<ll> &point2, ll m)
{
    ll num = mid;
    ll max_m = 0;
    for (int i = 0; i <= cnt_2; i++)
    {
        if (num >= i * 2)
        {
            ll x = i, y;
            if (num - i * 2 > cnt_1)
            {
                y = cnt_1;
            }
            else
            {
                y = num - i * 2;
            }
            max_m = max(point1[y] + point2[x], max_m);
        }
    }
    return max_m >= m;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<ll> av(n), bv(n);
    for (auto &x : av)
        cin >> x;
    for (auto &x : bv)
        cin >> x;
    vector<ll> point1, point2;
    ll cnt_1 = 0, cnt_2 = 0;
    for (i = 0; i < n; i++)
    {
        if (bv[i] == 1)
        {
            cnt_1++;
            point1.push_back(av[i]);
        }
        else if (bv[i] == 2)
        {
            cnt_2++;
            point2.push_back(av[i]);
        }
    }
    sort(point1.begin(), point1.end());
    point1.push_back(0);
    reverse(point1.begin(), point1.end());
    for (i = 1; i < point1.size(); i++)
    {
        point1[i] = point1[i - 1] + point1[i];
    }

    sort(point2.begin(), point2.end());
    point2.push_back(0);
    reverse(point2.begin(), point2.end());
    for (i = 1; i < point2.size(); i++)
    {
        point2[i] = point2[i - 1] + point2[i];
    }

    ll hi = accumulate(bv.begin(), bv.end(), 0LL), lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pff(mid, cnt_1, cnt_2, point1, point2, m))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (pff(lo, cnt_1, cnt_2, point1, point2, m))
        cout << lo << endl;
    else if (pff(hi, cnt_1, cnt_2, point1, point2, m))
        cout << hi << endl;
    else
        cout << -1 << endl;
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