#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

bool pf(ll n, ll k)
{
    return n >= k;
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
    vector<ll> ans;
    for (i = n - 1; i >= 0; i--)
    {
        ll hi = i, lo = 0, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (pf(v[mid], i - mid + 1))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf(v[lo], i - lo + 1))
            ans.push_back(i - lo + 1);
        else
            ans.push_back(i - hi + 1);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << gap;
    cout << endl;
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