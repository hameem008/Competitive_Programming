#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> divisors(ll n)
{
    vector<ll> ans;
    if (n == 1)
        return ans;
    ll i = 1;
    ans.push_back(n);
    for (i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
    if (i * i == n)
        ans.push_back(i);
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        mp[a]++;
    }
    ll ans = 0;
    for (auto x : mp)
    {
        if (x.first > 1e6)
        {
            for (b = 2; b * x.first <= (--mp.end())->first; b++)
            {
                if (x.first % b == 0 && mp.find(x.first * b) != mp.end() && mp.find(x.first / b) != mp.end())
                {
                    ans += mp[x.first / b] * x.second * mp[x.first * b];
                }
            }
        }
        else
        {
            for (auto y : divisors(x.first))
            {
                if (mp.find(x.first / y) != mp.end() && mp.find(x.first * y) != mp.end())
                {
                    ans += mp[x.first / y] * x.second * mp[x.first * y];
                }
            }
        }
        ans += x.second * (x.second - 1) * (x.second - 2);
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