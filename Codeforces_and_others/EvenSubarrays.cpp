#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> nums, v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> prexor(n);
    prexor[0] = v[0];
    for (i = 1; i < n; i++)
    {
        prexor[i] = prexor[i - 1] ^ v[i];
    }
    for (i = 0; i * i <= 2 * n; i++)
    {
        nums.push_back(i * i);
    }
    ll ans = 0;
    for (i = 0; i < nums.size(); i++)
    {
        ll num = nums[i];
        vector<ll> mp(2 * n + 1, 0);
        for (j = 0; j < n; j++)
        {
            ll xorr = num ^ prexor[j];
            if (xorr <= 2 * n)
            {
                ans += mp[xorr];
                if (prexor[j] == num)
                    ans++;
            }
            mp[prexor[j]]++;
        }
    }
    cout << n * (n + 1) / 2 - ans << endl;
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