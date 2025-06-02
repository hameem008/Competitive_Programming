#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool pf(ll mid, ll k, vector<ll> &v)
{
    bool flag = true;
    ll pos_of_mid = mid;
    for (int i = 1; i <= k; i++)
    {
        if (i == 1)
        {
            if (binary_search(v.begin(), v.end(), mid))
            {
                flag = false;
                break;
            }
        }
        else
        {
            ll pos = lower_bound(v.begin(), v.end(), mid) - v.begin();
            if (binary_search(v.begin(), v.end(), pos))
            {
                flag = false;
                break;
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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
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