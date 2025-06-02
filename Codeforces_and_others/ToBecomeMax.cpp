#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

bool pf(ll mid, vector<ll> v, ll k)
{
    bool ret = false;
    for (int i = 0; i < v.size(); i++)
    {
        ll temp_k = 0;
        if (v[i] >= mid)
        {
            ret = true;
        }
        else
        {
            for (int j = 0; j < v.size() - i; j++)
            {
                if (v[i + j] < mid - j)
                {
                    temp_k += (mid - j - v[i + j]);
                }
                else
                {
                    if (temp_k <= k)
                    {
                        ret = true;
                    }
                    break;
                }
            }
        }
    }
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
    {
        cin >> x;
    }
    ll hi = k + *max_element(v.begin(), v.end()), lo = *max_element(v.begin(), v.end()), mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, v, k))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf(hi, v, k))
        cout << hi << endl;
    else
        cout << lo << endl;
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